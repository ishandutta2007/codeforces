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
    var (n,t)=readInts()
    if(t<10)printLine(Array(n){if(it==0)t else 0}.joinToString(""))
    else if(n==1)printLine("-1")
    else printLine(Array(n-1){if(it==0)t else 0}.joinToString(""))
    output()
}