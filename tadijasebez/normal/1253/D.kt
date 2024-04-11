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

class DisjointSetUnion(val n:Int){
    var p=Array(n){it}
    fun cl(){p=Array(n){it}}
    fun Find(x:Int):Int{
        if(p[x]==x)return x
        else{p[x]=Find(p[x]);return p[x]}
    }
    fun Union(x:Int,y:Int){p[Find(x)]=Find(y)}
    fun Con(x:Int,y:Int)=Find(x)==Find(y)
}

fun main(){
    val(n,m)=ris()
    val DSU=DisjointSetUnion(n)
    for(i in 0 until m){
        var(u,v)=ris();u--;v--
        DSU.Union(u,v)
    }
    data class Range(val l:Int,val r:Int)
    val intervals=ArrayList<Range>()
    val L=Array(n){n};val R=Array(n){-1}
    for(i in 0 until n){
        L[DSU.Find(i)]=min(L[DSU.Find(i)],i)
        R[DSU.Find(i)]=max(R[DSU.Find(i)],i)
    }
    for(i in 0 until n)if(R[i]!=-1)intervals.add(Range(L[i],R[i]))
    intervals.sortWith(compareBy({it.l},{it.r}))
    var mxr=-1;var ans=0
    for(interval in intervals){
        if(interval.l<=mxr)ans++
        mxr=max(mxr,interval.r)
    }
    pln(ans)
    output()
}