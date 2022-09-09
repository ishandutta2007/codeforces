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
    val(n,k)=ris()
    val a=ris()
    var top=n;var bot=1;var ans=0
    while(top>=bot){
        var mid=(top+bot) shr 1
        var pref=Array(n+1){0}
        for(i in 0 until n)pref[i+1]=pref[i]+(if(a[i]>=mid)1 else -1)
        //pln("mid $mid")
        //pln(pref)
        var mn=0
        var ok=false
        for(i in k..n){
            if(pref[i]-mn>0)ok=true
            mn=min(mn,pref[i-k+1])
        }
        if(ok){ans=mid;bot=mid+1}
        else top=mid-1
    }
    pln(ans)
    output()
}