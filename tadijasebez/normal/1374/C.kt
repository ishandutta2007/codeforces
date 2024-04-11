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
        var n=readInt()
        var s=readLn()
        var bal=0;var mn=0
        for(c in s){
            if(c=='(')bal++
            else bal--
            mn=min(mn,bal)
        }
        printLine("${-mn}")
    }
    output()
}