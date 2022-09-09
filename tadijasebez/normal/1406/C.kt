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

class Centroid(val E:Array<ArrayList<Int>>){
    val n=E.size
    var sz=Array(n){0};var par=Array(n){-1};var ptr=Array(n){0}
    fun DFS(root:Int){
        ptr=Array(n){0};par=Array(n){-1}
        val stk=Stack<Int>()
        stk.push(root)
        while(stk.isNotEmpty()){
            val u=stk.pop()
            if(ptr[u]==0){
                sz[u]=1
            }
            if(ptr[u]==E[u].size){
                if(par[u]!=-1)sz[par[u]]+=sz[u]
            }else{
                val v=E[u][ptr[u]++]
                if(v==par[u]){stk.push(u);continue}
                par[v]=u
                stk.push(u)
                stk.push(v)
            }
        }
    }
    fun Find(root:Int):Int{
        var u=root
        while(true){
            var ok=false
            for(v in E[u])if(v!=par[u]&&sz[v]*2>=sz[root]){u=v;ok=true;break}
            if(!ok)break
        }
        return u
    }
}

fun main(){
    val t=ri()
    for(tc in 1..t){
        val n=ri()
        val E=Array(n){ArrayList<Int>()}
        for(i in 1 until n){
            var(u,v)=ris();u--;v--
            E[u].add(v);E[v].add(u)
        }
        var G=Centroid(E)
        G.DFS(0)
        var cen=G.Find(0)
        var leaf=cen
        while(E[leaf].size>1){
            leaf=if(E[leaf][0]==G.par[leaf])E[leaf][1] else E[leaf][0]
        }
        if(G.sz[cen]*2==n){
            pln("${leaf+1} ${G.par[leaf]+1}\n${leaf+1} ${G.par[cen]+1}")
        }else pln("${leaf+1} ${G.par[leaf]+1}\n${leaf+1} ${G.par[leaf]+1}")
    }
    output()
}