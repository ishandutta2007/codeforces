import java.util.*
import kotlin.math.*

fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun readdoubles() = ArrayList(readstrings().map { it.toDouble() })

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var n=readint()
        var ans=0.0
        var t=PI/n
        var s=t/4
        for(i in 0..n-1){
            ans+=sin(t*i+s)
        }
        println("$ans")
    }
}