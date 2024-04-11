import java.util.*
import java.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts()  = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs()  = readLn().split(" ").map{it.toLong()}

val out = mutableListOf<String>()
fun printLine(s: String) { out.add(s) }
fun output() { println(out.joinToString("\n")) }

fun main(){
    var t = readInt()
    for(tt in 1..t){
        var (n, a, b) = readInts()
        var ans = charArrayOf()
        for(i in 1..b)
            ans+=(('a'.toInt()+i-1).toChar())
        for(i in b+1..a)
            ans+=('a')
        for(i in a+1..n)
            ans+=(ans[i-a-1])
        printLine(ans.joinToString(""))
    }
    output()
}