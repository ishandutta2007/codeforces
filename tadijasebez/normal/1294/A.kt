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
    val t=readInt()
    repeat(t){
        var (a,b,c,n)=readInts()
        var mx=max(a,max(b,c))
        var mn=mx-a+mx-b+mx-c
        printLine(if(n<mn||(n-mn)%3!=0)"NO" else "YES")
    }
    output()
}