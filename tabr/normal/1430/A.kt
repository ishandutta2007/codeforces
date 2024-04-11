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
        var ans="-1"
        for(i in 0..1000){
            if(3*i>n){
                break
            }
            for(j in 0..1000){
                if(3*i+5*j>n){
                    break
                }
                if((n-3*i-5*j)%7==0){
                    ans=i.toString()+" "+j.toString()+" "+((n-3*i-5*j)/7).toString()
                }
            }
        }
        println(ans)
    }
}