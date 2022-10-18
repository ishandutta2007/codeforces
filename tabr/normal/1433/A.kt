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
    var tt=readint()
    while(tt-->0){
        var x=readint()
        var ans=0;
        for(i in 1 until x%10){
            ans+=10
        }
        var t=1
        while(x>0){
            ans+=t
            t++
            x/=10
        }
        println("$ans")
    }
}