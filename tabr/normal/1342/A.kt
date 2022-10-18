import java.util.*
import kotlin.math.*

fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var(x,y)=readlongs()
        var(a,b)=readlongs()
        b=min(a*2,b)
        println("${min(x,y)*b+(max(x,y)-min(x,y))*a}")
    }
}