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

val inf=9e18.toLong()
fun main(){
    val(n,m,k)=ris()
    val a=rls()
    val b=rls()
    val c=Array(n){rls()}
    data class C(val x:Long,var y:Long)
    val pts=ArrayList<C>()
    var pi=0;var pj=0
    while(pi<n||pj<m){
        if(pi==n||(pj!=m&&b[pj]<a[pi])){
            for(z in 0 until pi)pts.add(C(b[pj],c[z][pj]))
            pj++
        }else{
            for(z in 0 until pj)pts.add(C(a[pi],c[pi][z]))
            pi++
        }
    }
    //pts.sortWith(compareBy({it.x},{-it.y}))
    val hull=ArrayList<C>()
    for(pt in pts){
        if(hull.isNotEmpty()&&hull.last().x==pt.x&&hull.last().y<pt.y)hull.removeAt(hull.size-1)
        if(hull.isEmpty()||hull.last().y<pt.y)hull.add(pt)
    }
    fun Solve():Long{
        var now=0L
        var exp=0L;var mx=0L
        for(i in 0 until hull.size){
            val need=if(i+1==hull.size)max(a.last(),b.last()) else hull[i+1].x
            mx=max(mx,hull[i].y)
            if(exp<need){
                val dif=need-exp
                val take=(dif+mx-1)/mx
                now+=take
                exp+=take*mx
            }
        }
        return now
    }
    var ans=inf
    for(chose in 0 until hull.size){
        hull[chose].y+=k
        ans=min(ans,Solve())
        hull[chose].y-=k
    }
    pln(ans)
    output()
}