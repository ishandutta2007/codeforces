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
        var s=readln()
        var a=0
        var b=0
        for(c in s){
            if(c=='0'){
                a=1
            }else{
                b=1
            }
        }
        var ans=""
        if(a==0){
            for(i in 1..s.length){
                ans+="1"
            }
        }else if(b==0){
            for(i in 1..s.length){
                ans+="0"
            }
        }else{
            for(i in 1..s.length){
                ans+="01"
            }
        }
        println(ans)
    }
}