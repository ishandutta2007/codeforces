//
//

import java.util.*
import java.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{it.toLong()}

val out = mutableListOf<String>()
fun printLine(s: String) { out.add(s) }
fun output() { println(out.joinToString("\n")) }

fun main(){
    var t=readInt()
    for(tc in 1..t){
        var n=readInt()
        var m=3
        while(n%m!=0)m=m*2+1
        printLine("${n/m}")
    }
    output();
}