import java.util.*
import kotlin.math.*

import java.io.BufferedReader
import java.io.InputStreamReader
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendln(s)

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var n=readint()
        var a=LongArray(n)
        var b=LongArray(n)
        var d=1e18.toLong()
        for(i in 0..n-1){
            var(x,y)=readln().split(" ").map{it.toLong()}
            a[i]=x
            b[i]=y
            d=min(d,x)
        }
        var c=0L
        for(i in 0..n-1){
            c+=max(0L,a[i]-b[(i+n-1)%n])
            if(a[i]>b[(i+n-1)%n]){
                d=min(d,b[(i+n-1)%n])
            }
        }
        cout("${c+d}")
    }
    print(output)
}