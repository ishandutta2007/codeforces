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
        var n=readint()
        var a=readints()
        var ans=n-a.sum()
        for(i in 0..n-1){
            if(a[i]==1){
                ans-=i
                break
            }
        }
        for(i in n-1 downTo 0){
            if(a[i]==1){
                ans-=n-1-i
                break
            }
        }
        println("$ans")
    }
}