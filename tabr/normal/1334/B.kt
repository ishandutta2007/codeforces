import java.util.*
import kotlin.math.*

fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var (n,x)=readints()
        var a=readints()
        a.sort()
        a.reverse()
        var ans=0
        var sum=0L
        while(ans<n && sum+a[ans]>=1L*(ans+1)*x){
            sum+=a[ans]
            ans++
        }
        println("$ans")
    }
}