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
    var n=readLong()
    var luc=0
    while(n>0){
        if(n%10==4L||n%10==7L)luc++
        n/=10
    }
    if(luc==4||luc==7)printLine("YES")
    else printLine("NO")
    output()
}