import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
    var tt=readint()
    while(tt-- > 0){
        var n=readint()
        var a=readlongs()
        var b=readlongs()
        var ans=0L
        var x=100000000000L
        var y=100000000000L
        for(i in 0..n-1){
            x=minOf(x,a[i])
            y=minOf(y,b[i])
        }
        for(i in 0..n-1){
            ans+=maxOf(a[i]-x,b[i]-y)
        }
        println(ans)
    }
}