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
    val(n,m)=ris()
    data class Seg(val l:Int,val r:Int,val t:Int)
    val a=ArrayList<Seg>()
    for(i in 0 until n){
        val(l,r)=ris()
        a.add(Seg(l,r,i))
    }
    val all=TreeSet<Pair<Int,Int>>(compareBy({it.first},{it.second}))
    for(i in 0 until m){
        val(l,r)=ris()
        a.add(Seg(l-1,r+1,-1))
        all.add(Pair(l,r))
    }
    a.sortWith(compareBy({it.r-it.l},{it.t}))
    val N=1000050;
    val mx=Array(2*N){-1}
    val ans=Array(n){-1}
    for((l,r,t) in a){
        if(t==-1){
            mx[l+r]=max(mx[l+r],r-l-1)
        }else{
            if(all.contains(Pair(l,r))){
                ans[t]=0
            }else if(mx[l+r]!=-1&&mx[l+r-2]!=-1&&mx[l+r+2]!=-1){
                ans[t]=((r-l+1)-max(mx[l+r],min(mx[l+r-2],mx[l+r+2])))/2
            }else if(mx[l+r]!=-1){
                ans[t]=((r-l+1)-mx[l+r])/2
            }else if(mx[l+r-2]!=-1&&mx[l+r+2]!=-1){
                ans[t]=((r-l+1)-min(mx[l+r-2],mx[l+r+2]))/2
            }
        }
    }
    pln(ans)
    output()
}