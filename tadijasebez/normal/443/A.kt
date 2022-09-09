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
    var str=readLn()
    str=str.substring(1..str.length-2)
    var lst=str.split(", ")
    var st=TreeSet<String>()
    for(i in lst)if(i!="")st.add(i)
    printLine("${st.size}")
    output()
}