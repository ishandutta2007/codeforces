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
        println("2")
        if(n==2){
            println("1 2")
            continue
        }
        var a=ArrayList<Pair<Int,Int>>();
        a.add(Pair(n,n-2))
        a.add(Pair(n-1,n-1))
        for(i in n-3 downTo 1){
            a.add(Pair(i,i+2))
        }
        println(a.joinToString("\n",transform={it->"${it.first} ${it.second}"}))
    }
}