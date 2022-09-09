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
    var k=readInt()
    var l=readInt()
    var m=readInt()
    var n=readInt()
    var d=readInt()
    var ans=0
    for(i in 1..d){
        if(i%k==0||i%l==0||i%m==0||i%n==0)ans++
    }
    printLine("$ans")
    output()
}