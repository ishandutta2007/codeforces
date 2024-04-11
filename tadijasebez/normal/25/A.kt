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
    var n=readInt()
    var a=readInts().toIntArray()
    var odd=0
    for(i in 0 until n){
        if(a[i]%2==1)odd++
    }
    if(odd!=1)odd=0
    for(i in 0 until n){
        if(a[i]%2==odd)printLine("${i+1}")
    }
    output()
}