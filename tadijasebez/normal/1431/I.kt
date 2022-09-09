import java.util.*
import kotlin.math.*

fun rs()=readLine()!!
fun ri()=rs().toInt()
fun rl()=rs().toLong()
fun rd()=rs().toDouble()
fun ris()=rs().split(" ").map{it.toInt()}
fun rls()=rs().split(" ").map{it.toLong()}
fun rds()=rs().split(" ").map{it.toDouble()}

val out=mutableListOf<String>()
fun pln(s:String){out.add(s)}
fun pln(i:Int)=pln(i.toString())
fun pln(l:Long)=pln(l.toString())
fun pln(d:Double,precision:Int=12)=pln(("%."+precision.toString()+"f").format(d))
fun pln(a:IntArray)=pln(a.joinToString(" "))
fun pln(a:LongArray)=pln(a.joinToString(" "))
fun<T> pln(a:Array<T>)=pln(a.joinToString(" "))
fun<T> pln(a:ArrayList<T>)=pln(a.joinToString(" "))
fun output(){println(out.joinToString("\n"))}

/*class SuffixArray(val n:Int){
    val str=Array(n){0}
    var tsz=0
    val sa=Array(n){0};val lcp=Array(n){0};val id=Array(n){0}
    fun AddChar(c:Int):Int{
        str[++tsz]=c
        return tsz
    }
    val F=Array(n){0};val S=Array(n){0}
    fun BuildSA(){
        str[++tsz]=-1
        for(i in 1..tsz)id[i]=str[i]
        var j=1
        while(true){
            val ord=Array(tsz){it+1}
            for(i in 1..tsz){
                F[i]=id[i];S[i]=if(i+j<=tsz)id[i+j] else 0
            }
            ord.sortWith(compareBy({F[it]},{S[it]}))
            var c=0
            for(i in 0 until tsz){
                id[ord[i]]=c+1
                if(i+1==tsz)c++
                else{
                    if(S[i]!=S[i+1]||F[i]!=F[i+1])c++
                }
            }
            if(c==tsz)break
            j*=2
        }
        for(i in 1..tsz)sa[id[i]]=i
    }
    fun BuildLCP(){
        var k=0
        for(i in 1..tsz){
            if(id[i]!=tsz){
                var j=sa[id[i]+1]
                while(max(i,j)+k<=tsz&&str[i+k]==str[j+k])k++
                lcp[id[i]]=k
                if(k>0)k--
            }
        }
    }
}*/

fun<T:Comparable<T>> ArrayList<T>.lower_bound(x:T):Int{
    var top=this.size;var bot=0
    while(top>bot){
        val mid=(top+bot) shr 1
        if(this[mid]<x)bot=mid+1
        else top=mid
    }
    return bot
}
fun<T:Comparable<T>> ArrayList<T>.upper_bound(x:T):Int{
    var top=this.size;var bot=0
    while(top>bot){
        val mid=(top+bot) shr 1
        if(this[mid]<=x)bot=mid+1
        else top=mid
    }
    return bot
}
fun<T:Comparable<T>> Array<T>.lower_bound(x:T):Int{
    var top=this.size;var bot=0
    while(top>bot){
        val mid=(top+bot) shr 1
        if(this[mid]<x)bot=mid+1
        else top=mid
    }
    return bot
}
fun<T:Comparable<T>> Array<T>.upper_bound(x:T):Int{
    var top=this.size;var bot=0
    while(top>bot){
        val mid=(top+bot) shr 1
        if(this[mid]<=x)bot=mid+1
        else top=mid
    }
    return bot
}

class SuffixTree(var _N:Int){
    var link=Array(_N){0};var st=Array(_N){0};var len=Array(_N){0}
    var go=Array(_N){TreeMap<Char,Int>()}
    var is_leaf=Array(_N){false}
    var tsz=0;var root=0
    fun AddNode(s:Int,l:Int):Int{
        tsz++
        len[tsz]=l;st[tsz]=s
        link[tsz]=root
        return tsz
    }
    var str=Array(_N){' '};var n=0
    fun Add(s:String){
        if(root==0){root=AddNode(-1,0);link[root]=root}
        var atnode=root;var atedge=n;var atlen=0;var pleaf=0;var pnode=0
        val f=n
        for(i in 0 until s.length)str[n++]=s[i]
        for(i in f..n){
            while(true){
                val tonode=if(atedge==n||!go[atnode].containsKey(str[atedge]))0 else go[atnode][str[atedge]]!!
                if(tonode!=0 && atlen>=len[tonode]){
                    atlen-=len[tonode]
                    atedge+=len[tonode]
                    atnode=tonode
                    continue
                }
                if(tonode==0){
                    if(i!=n){
                        val leaf=AddNode(i,n-i)
                        go[atnode][str[i]]=leaf
                        is_leaf[leaf]=true
                        if(pleaf!=0)link[pleaf]=leaf
                        pleaf=leaf
                    }else{
                        is_leaf[atnode]=true
                        if(pleaf!=0)link[pleaf]=atnode
                        pleaf=0
                    }
                    if(pnode!=0)link[pnode]=atnode
                    pnode=0
                }else if(i==n || str[st[tonode]+atlen]!=str[i]){
                    val node=AddNode(st[tonode],atlen)
                    len[tonode]-=atlen;st[tonode]+=atlen
                    go[atnode][str[st[node]]]=node
                    go[node][str[st[tonode]]]=tonode
                    if(i!=n){
                        val leaf=AddNode(i,n-i)
                        go[node][str[i]]=leaf
                        is_leaf[leaf]=true
                        if(pleaf!=0)link[pleaf]=leaf
                        pleaf=leaf
                    }else{
                        is_leaf[node]=true
                        if(pleaf!=0)link[pleaf]=node
                        pleaf=0
                    }
                    if(pnode!=0)link[pnode]=node
                    pnode=node
                }else{
                    if(pnode!=0)link[pnode]=atnode
                    pnode=0
                    atlen++
                    break
                }
                if(atnode==root){
                    atedge++
                    if(atlen>0)atlen--
                    else break
                }else atnode=link[atnode]
            }
        }
    }
    var lid=Array(_N){0};var rid=Array(_N){0};var tid=0
    val All=Array(_N){ArrayList<Int>()}
    fun DFS(u:Int,d:Int){
        lid[u]=++tid
        if(is_leaf[u]){
            All[d].add(tid)
        }
        for(c in go[u].keys){
            val v=go[u][c]!!
            DFS(v,d+len[v])
        }
        rid[u]=tid
    }
    data class State(var atnode:Int,var atlen:Int,var atedge:Char)
    fun Move(cur:State,c:Char):State{
        if(cur.atlen==-1)return cur
        if(cur.atlen==0){
            if(go[cur.atnode].containsKey(c)) {
                val tonode=go[cur.atnode][c]!!
                if(len[tonode]==1)return State(tonode,0,' ')
                else return State(cur.atnode,1,c)
            }else return State(cur.atnode,-1,' ')
        }else{
            val tonode=go[cur.atnode][cur.atedge]!!
            if(c!=str[st[tonode]+cur.atlen])return State(cur.atnode,-1,' ')
            if(cur.atlen+1==len[tonode])return State(tonode,0,' ')
            else return State(cur.atnode,cur.atlen+1,cur.atedge)
        }
    }
    fun RS():State{
        return State(root,0,' ')
    }
    fun Bad(cur:State,dep:Int):Boolean{
        if(cur.atlen==-1)return true
        var node=cur.atnode
        if(cur.atlen>0)node=go[cur.atnode][cur.atedge]!!
        val idx=All[dep].lower_bound(lid[node])
        if(idx==All[dep].size || All[dep][idx]>rid[node])return true
        return false
    }
}

val N=1000050
fun main(){
    val(n,m,q)=ris()
    val str=Array(n){rs()}
    val qs=Array(q){rs()}
    val ST=SuffixTree(N)
    for(i in 0 until n){
        ST.Add(str[i])
    }
    ST.DFS(ST.root,0)
    for(i in 0 until q){
        var now=ST.RS()
        var dep=m;var ans=0
        var ok=true
        for(j in 0 until m){
            now=ST.Move(now,qs[i][j])
            if(now.atlen==-1||ST.Bad(now,dep)){
                ans++
                now=ST.RS()
                dep=m-j
                now=ST.Move(now,qs[i][j])
                if(now.atlen==-1||ST.Bad(now,dep)){
                    ok=false;break
                }
            }
        }
        if(!ok)pln(-1)
        else pln(ans)
    }
    /*val sst=Array(n){0}
    val qst=Array(n){0}
    val SA=SuffixArray(N)
    for(i in 0 until n){
        sst[i]=SA.tsz+1
        for(c in str[i])SA.AddChar(c.toByte().toInt())
    }
    for(i in 0 until q){
        qst[i]=SA.tsz+1
        for(c in str[i])SA.AddChar(c.toByte().toInt())
    }*/
    output()
}