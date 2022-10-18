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
    var tt = readint()
    while (tt-- > 0) {
        var n=readint()
        var t=readints()
        var s=t.toMutableList()
        s.sort()
        var ans=10000000
        for(i in 0..n-2){
            ans=minOf(ans,s[i+1]-s[i])
        }
        println(ans)
    }
}

// kotlin sol.jar<in>out