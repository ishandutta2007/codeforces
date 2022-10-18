import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var(n,k)=readints()
    var a=readints()
    a.sort()
    var dp=Array(n+1){IntArray(k+1)}
    for(i in 0..n-1){
        for(j in 0..k){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j])
        }
        for(j in 1..k){
            if(i+1-j*2<0){
                break
            }
            var t=0
            for(l in 0..j-1){
                t+=a[i-l]-a[i-j*2+l+1]
            }
            for(l in j..k){
                dp[i+1][l]=max(dp[i+1][l],dp[i+1-j*2][l-j]+t)
            }
        }
    }
    println(dp[n][k])
}

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendln(s)
fun cout(s: Int) = output.appendln(s.toString())
fun cout(s: Long) = output.appendln(s.toString())