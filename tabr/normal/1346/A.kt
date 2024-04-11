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
        var (n,k)=readints()
        var a=IntArray(4)
        a[0]=n/(1+k+k*k+k*k*k)
        for(i in 1..3){
            a[i]=a[i-1]*k
        }
        println(a.joinToString(" "))
    }
}