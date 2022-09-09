import java.util.*
import kotlin.collections.ArrayList
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
    val cnt=Array(n+1){0}
    var arr=ArrayList<Int>(n)
    for(i in 1..n){
        var j=i*2
        var c=0
        while(j<=n){
            cnt[j]++
            c++
            j+=i
        }
        arr.add(cnt[i]-c)
    }
    arr.sort()
    arr.reverse()
    val ans=ArrayList<Int>()
    ans.add(arr[0])
    for(i in 1 until n)ans.add(ans.last()+arr[i])
    pln(ans)
    output()
}