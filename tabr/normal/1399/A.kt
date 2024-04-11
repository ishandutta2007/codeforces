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
        var a=readints()
        var b=a.sorted()
        var ans="YES"
        for(i in 0..n-2){
            if((b[i]+1==b[i+1]) or (b[i]==b[i+1])){
                continue
            }
            ans="NO"
        }
        println(ans)
    }
}