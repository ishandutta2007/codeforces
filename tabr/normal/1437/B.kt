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
        var s=readln()
        var a=0
        var b=0
        var c=-1
        for(i in 0..n-1){
            if(s[i]-'0'==i%2){
                if(c!=0){
                    a++
                    c=0
                }
            }else{
                if(c!=1){
                    b++
                    c=1
                }
            }
        }
        println("${minOf(a,b)}")
    }
}