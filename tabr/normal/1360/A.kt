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
        var (a,b)=readints()
        if(a>b){
            var c=a
            a=b
            b=c
        }
        var n=maxOf(a*2,b)
        println(n*n)
    }
}

// kotlin sol.jar<in>out