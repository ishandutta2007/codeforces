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
    var (h,w,k)=readints()
    var inf=1e8.toInt()
    var dp=IntArray(k){-inf}
    dp[0]=0
    for(i in 0..h-1){
        var a=readints()
        var c=IntArray(5000){inf}
        c[0]=0
        for(l in a){
            for(j in 4900 downTo 0){
                c[j+l]=minOf(c[j+l],c[j]+1)
            }
        }
        var t=IntArray(k,{-inf})
        for(j in 0..4900){
            if(c[j]*2<=w){
                t[j%k]=j
            }
        }
        var ndp=dp.copyOf()
        for(j in 0..k-1){
            for(l in 0..k-1){
                if(t[l]<0){
                    continue
                }
                ndp[(j+l)%k]=maxOf(ndp[(j+l)%k],dp[j]+t[l])
            }
        }
        dp=ndp.copyOf()
    }
    println("${dp[0]}")
}