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
    var a=readLn()
    var b=readLn()
    var x=abs(a[0]-b[0])
    var y=abs(a[1]-b[1])
    var ch1=if(a[0]>b[0])'L' else 'R'
    var ch2=if(a[1]>b[1])'D' else 'U'
    printLine("${max(x,y)}")
    repeat(min(x,y)){printLine("$ch1$ch2")}
    for(i in 1..x-y){printLine("$ch1")}
    for(i in 1..y-x){printLine("$ch2")}
    output()
}