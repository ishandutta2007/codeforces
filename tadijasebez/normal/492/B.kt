import java.util.*
import java.math.*
import kotlin.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

fun main(){
    var (n,l)=readInts()
    var a=readInts().toIntArray()
    a.sort()
    var ans=max(a[0]+0.0,l-a[n-1]+0.0)
    for(i in 1 until n)ans=max(ans,(a[i]-a[i-1])/2.0)
    printLine("%.12f".format(ans))
    output()
}