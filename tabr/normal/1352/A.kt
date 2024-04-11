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
    var t=readint()
    while(t-- > 0){
        var n=readint()
        var ans = mutableListOf<Int>()
        var s=1
        while(n>0){
            if(n%10!=0){
                ans.add(n%10*s)
            }
            n/=10
            s*=10
        }
        println(ans.size)
        println(ans.joinToString(" "))
    }
}