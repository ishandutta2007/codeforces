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

class MinCostMaxFlow(n:Int){
    class Edge(u:Int,v:Int,c:Long,w:Long){
        val u=u;val v=v;var c=c;val w=w
    }
    val n=n
    val G=Array(n){ArrayList<Int>()}
    val edges=ArrayList<Edge>()
    fun AddEdge(u:Int,v:Int,c:Long,w:Long){
        G[u].add(edges.size);edges.add(Edge(u,v,c,w))
        G[v].add(edges.size);edges.add(Edge(v,u,0,-w))
    }
    val inf=9e18.toLong()
    var dist=Array(n){inf}
    var inq=Array(n){false}
    val go=Array(n){0}
    fun spfa(s:Int,t:Int):Boolean{
        dist=Array(n){inf}
        inq=Array(n){false}
        val q=LinkedList<Int>()
        dist[s]=0.toLong()
        q.add(s)
        while(!q.isEmpty()){
            val u=q.remove()
            inq[u]=false
            for(e in G[u]){
                var v=edges[e].v;var c=edges[e].c;var w=edges[e].w
                if(c>0&&dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w
                    go[v]=e
                    if(!inq[v]){q.add(v);inq[v]=true}
                }
            }
        }
        return dist[t]!=inf
    }
    fun MCMF(s:Int,t:Int):Long{
        var ans=0.toLong();var flow=0.toLong()
        while(spfa(s,t)){
            var cut=inf;var i:Int
            i=t;while(i!=s){cut=min(cut,edges[go[i]].c);i=edges[go[i]].u}
            i=t;while(i!=s){edges[go[i]].c-=cut;edges[go[i] xor 1].c+=cut;i=edges[go[i]].u}
            flow+=cut
            ans+=dist[t]*cut
        }
        return ans
    }
}

fun main(){
    val t=ri()
    for(tc in 1..t){
        val n=ri()
        val a=ris()
        val s=n*3;val t=s+1
        val mcmf=MinCostMaxFlow(n*3+2)
        for(i in 0 until n){
            for(j in 1..2*n){
                mcmf.AddEdge(i,j+n-1,1,abs(a[i]-j).toLong())
            }
            mcmf.AddEdge(s,i,1,0)
        }
        for(i in 1..2*n)mcmf.AddEdge(i+n-1,t,1,0)
        pln(mcmf.MCMF(s,t))
    }
    output()
}