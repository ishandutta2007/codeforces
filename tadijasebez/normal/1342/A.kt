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
    var t=readInt()
    for(tc in 1..t){
        var (x,y)=readLongs()
        var (a,b)=readLongs()
        b=min(b,a*2)
        var ans=min(x,y)*b+abs(x-y)*a
        printLine("$ans")
    }
    output()
}