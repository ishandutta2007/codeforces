import java.util.*
import java.math.*
import kotlin.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

val N=50005
val M=4*N
var mn=Array(M){0}
var lzy=Array(M){0}
fun Add(c:Int,ss:Int,se:Int,qs:Int,qe:Int,x:Int){
    if(qs>qe||qs>se||ss>qe)return
    if(qs<=ss&&qe>=se){mn[c]+=x;lzy[c]+=x;return}
    var mid=(ss+se)/2
    Add(c*2,ss,mid,qs,qe,x)
    Add(c*2+1,mid+1,se,qs,qe,x)
    mn[c]=min(mn[c*2],mn[c*2+1])+lzy[c]
}
fun Get(c:Int,ss:Int,se:Int,qs:Int,qe:Int):Int{
    if(qs<=ss&&qe>=se)return mn[c]
    var mid=(ss+se)/2
    if(qe<=mid)return Get(c*2,ss,mid,qs,qe)+lzy[c]
    if(qs>mid)return Get(c*2+1,mid+1,se,qs,qe)+lzy[c]
    return min(Get(c*2,ss,mid,qs,qe),Get(c*2+1,mid+1,se,qs,qe))+lzy[c]
}
fun main(){
    var str=readLn()
    var bal=0;var q=0;var n=str.length
    var idx=Array(n+1){0}
    var out=(" "+str).toCharArray()
    for(i in 1..n){
        if(str[i-1]==')'){
            bal--;Add(1,1,n,i,n,-1)
        }
        else{
            bal++;Add(1,1,n,i,n,1)
            if(str[i-1]=='?'){q++;idx[i]=q;out[i]='('}
        }
    }
    var cost=Array(q+1){0};var ans=0L
    for(i in 1..q){
        var (a,b)=readInts()
        ans+=a;cost[i]=b-a
    }
    if(bal%2!=0||Get(1,1,n,1,n)<0)printLine("-1")
    else{
        var ptr=n;var st=TreeSet<Pair<Int,Int>>(compareBy({it.first},{it.second}))
        while(ptr>0&&Get(1,1,n,ptr,n)>=2){
            if(idx[ptr]!=0)st.add(Pair(cost[idx[ptr]],ptr))
            ptr--
        }
        while(bal>0){
            if(st.isEmpty())break
            var tmp=st.first()
            st.remove(tmp)
            out[tmp.second]=')'
            ans+=tmp.first
            Add(1,1,n,tmp.second,n,-2)
            bal-=2
            while(ptr<n&&Get(1,1,n,ptr+1,n)<2){
                ptr++
                if(idx[ptr]!=0&&out[ptr]=='(')st.remove(Pair(cost[idx[ptr]],ptr))
            }
        }
        if(bal==0){
            printLine("$ans")
            printLine(out.slice(1..n).joinToString(""))
        }else printLine("-1")
    }
    output()
}