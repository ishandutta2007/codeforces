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
        var(a1,b1)=readints()
        var(a2,b2)=readints()
        if(a1>b1){
            var c=a1
            a1=b1
            b1=c
        }
        if(a2>b2){
            var c=a2
            a2=b2
            b2=c
        }
        if(b1==b2 && a1+a2 == b1){
            println("Yes")
        }else{
            println("No")
        }
    }
}