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
    val s=rs()
    val t=rs()
    val dpl=Array(n){0}
    var ptr=0
    for(i in 0 until n){
        if(ptr<m&&t[ptr]==s[i])ptr++
        dpl[i]=ptr
    }
    ptr=m-1
    val dpr=Array(n){0}
    for(i in n-1 downTo 0){
        if(ptr>=0&&t[ptr]==s[i])ptr--
        dpr[i]=ptr
    }
    ptr=0
    var ans=0
    for(i in 0 until n){
        while(ptr+1<n&&dpr[ptr+1]<m-1&&dpr[ptr+1]<dpl[i])ptr++
        if(dpl[i]>0)ans=max(ans,ptr-i)
    }
    pln(ans)
    output()
}