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
    var (n,m,d)=readints()
    var c=readints()
    var ans=IntArray(n)
    if(c.sum()+(m+1)*(d-1)<n){
        println("NO")
        return
    }
    var e=n-c.sum()
    var id=0
    for(i in 0..m-1){
        id+=min(e,d-1)
        e-=min(e,d-1)
        for(j in 0..c[i]-1){
            ans[id+j]=i+1
        }
        id+=c[i]
    }
    println("YES")
    println(ans.joinToString(" "))
}