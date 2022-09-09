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

fun main(){
    val(n1,n2,m)=ris()
    val k=ris().toIntArray()
    val E=Array(n1+n2){ArrayList<Int>()}
    repeat(m){
        val(u,v)=ris()
        E[u-1].add(v+n1-1)
        E[v+n1-1].add(u-1)
    }
    var nodes=0
    var edges=0
    var all=ArrayList<Int>()
    var was=Array(n1+n2){false}
    fun DFS(u:Int){
        was[u]=true
        nodes++
        if(u<n1)all.add(u)
        for(v in E[u]){
            edges++
            if(!was[v]){
                DFS(v)
            }
        }
    }
    var ans=0
    for(i in 0 until n1){
        if(!was[i]){
            nodes=0
            edges=0
            all.clear()
            DFS(i)
            if(edges/2==nodes-1){
                var mn=k[all[0]]
                for(j in all){
                    mn=min(mn,k[j])
                }
                ans+=mn
            }
        }
    }
    pln(ans)
    output()
}