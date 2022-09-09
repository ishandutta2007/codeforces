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

const val linf=9e18.toLong()

data class P(val dist:Long,val u:Int,val w:Int)
class PComparator{
    companion object:Comparator<P>{
        override fun compare(p1:P,p2:P):Int{
            if(p1.dist==p2.dist)return 0
            else if(p1.dist<p2.dist)return -1
            else return 1
        }
    }
}

class Graph(val n:Int,val m:Int){
    data class Edge(val v:Int,val w:Int)
    val E=Array(n+1){ArrayList<Edge>()}
    init{
        repeat(m){
            val(u,v,w)=ris()
            E[u].add(Edge(v,w))
            E[v].add(Edge(u,w))
        }
    }
    fun Dijkstra(u:Int):Array<Long>{
        val pq=PriorityQueue<P>(PComparator)
        val dist=Array(n+1){Array(51){linf}}
        dist[u][0]=0
        pq.add(P(0L,u,0))
        while(!pq.isEmpty()){
            val(d,u,w)=pq.remove()
            if(d!=dist[u][w])continue
            if(w==0){
                for((v,w1) in E[u]){
                    if(dist[v][w1]>dist[u][w]){
                        dist[v][w1]=dist[u][w]
                        pq.add(P(dist[v][w1],v,w1))
                    }
                }
            }else{
                for((v,w1) in E[u]){
                    if(dist[v][0]>dist[u][w]+(w+w1)*(w+w1)){
                        dist[v][0]=dist[u][w]+(w+w1)*(w+w1)
                        pq.add(P(dist[v][0],v,0))
                    }
                }
            }
        }
        return Array(n){dist[it+1][0]}
    }
}

fun main(){
    val(n,m)=ris()
    val G=Graph(n,m)
    var ans=G.Dijkstra(1)
    ans=Array(n){if(ans[it]==linf)-1L else ans[it]}
    pln(ans)
    output()
}