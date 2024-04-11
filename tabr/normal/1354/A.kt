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
        var(a,b,c,d)=readlongs()
        if(a<=b){
            println("$b")
        }else if(c<=d){
            println("-1")
        }else{
            println("${b+(a-b+c-d-1)/(c-d)*c}")
        }
    }
}