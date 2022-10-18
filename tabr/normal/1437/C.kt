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
        var t=readints()
        t.sort()
        var dp=Array(n + 1){IntArray(500){ 1000000000 }}
        dp[0][0]=0
        for(i in 0..n-1){
            var mn=dp[i][0]
            for(j in 1..400){
                dp[i+1][j]=minOf(dp[i+1][j],mn+abs(j-t[i]))
                mn=minOf(mn,dp[i][j])
            }
        }
        println("${dp[n].min()}")
    }
}