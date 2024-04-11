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
        var a=readints()
        var ans=1
        var vc=0
        var cur=0
        var pre=0
        for(i in 1..n-1){
            if(pre>a[i]){
                if(vc==0){
                    ans++
                    vc=cur-1
                    pre=a[i]
                    cur=1
                }else{
                    vc--
                    cur++
                    pre=a[i]
                }
            }else{
                cur++
                pre=a[i]
            }
        }
        println("$ans")
    }
}