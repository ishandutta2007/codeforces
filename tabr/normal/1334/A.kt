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
        var n=readint()
        var p=0
        var c=0
        var ans="YES"
        while(n-->0){
            var(x,y)=readints()
            if(y>x){
                ans="NO"
            }
            if(p>x || c>y){
                ans="NO"
            }
            if(x-p<y-c){
                ans="NO"
            }
            p=x
            c=y
        }
        println(ans)
    }
}