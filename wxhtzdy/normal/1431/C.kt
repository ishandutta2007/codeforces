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
    val t=ri()
    for(tc in 1..t){
        val (n,k)=ris()
        var a=ris()
        var ans=0
        var cnt=0
        var sum=0
        var cnt2=0
        for(j in 1..n){
            val i=n-j+1
            cnt++
            if(cnt%k==0)cnt2++
            if(cnt2>0){
                sum+=a[i-1]
                if(cnt%k!=0)sum-=a[i+cnt2-1]
            }
            ans=max(ans,sum)
        }
        pln(ans)
    }
    output()
    
}