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
    var a=readInt()
    var b=readInt()
    var c=readInt()
    var ans=a+b+c
    ans=max(ans,a+b*c)
    ans=max(ans,a*b+c)
    ans=max(ans,a*b*c)
    ans=max(ans,(a+b)*c)
    ans=max(ans,a*(b+c))
    printLine("$ans")
    output()
}