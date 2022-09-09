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
    val n=ri()
    val a=ris().toIntArray()
    a.sort()
    val b=ris().toIntArray()
    b.sort()
    //pln(a)
    //pln(b)
    val pref=Array(n+1){0}
    val suff=Array(n+1){0}
    for(i in 0 until n){
        pref[i]=b[i]-a[i]
        if(i>0)pref[i]=max(pref[i],pref[i-1])
    }
    //pln(pref)
    for(i in n downTo 1){
        suff[i]=b[i]-a[i-1]
        if(i<n)suff[i]=max(suff[i],suff[i+1])
    }
    //pln(suff)
    val q=ri()
    val c=ris()
    val ans=Array(q){0}
    for(i in 0 until q){
        var top=n-1
        var bot=0
        var pos=n
        while(top>=bot){
            var mid=(top+bot)/2
            if(a[mid]>=c[i]){
                pos=mid
                top=mid-1
            }else{
                bot=mid+1
            }
        }
        //pln(pos)
        ans[i]=b[pos]-c[i]
        if(pos!=0)ans[i]=max(ans[i],pref[pos-1])
        if(pos!=n)ans[i]=max(ans[i],suff[pos+1])
    }
    pln(ans)
    output()
}