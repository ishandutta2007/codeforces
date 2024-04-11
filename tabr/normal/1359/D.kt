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
    var tt = 1
    while (tt-- > 0) {
        var n=readint()
        var a=readints()
        var ans=0
        for(x in 30 downTo -30){
            var t=-100
            var s=0
            var mn=0
            for(i in 0..n-1){
                s+=a[i]
                t=maxOf(t,s-mn)
                mn=minOf(s,mn)
            }
            ans=maxOf(ans,t-x)
            for(i in 0..n-1){
                if(a[i]==x){
                    a[i]=-20000
                }
            }
        }
        println("$ans")
    }
}