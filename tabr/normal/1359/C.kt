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
        var(h,c,t)=readlongs()
        var ans=0L
        if(t>=h){
            ans++
        }else if(2*t<=c+h){
            ans=2L
        }else{
            ans=(h-c)/(2*t-h-c)
            if(ans%2L==0L){
                ans--
            }
            ans-=4L
            ans=maxOf(ans,1L)
            while((ans+2)*abs(h-c-(2*t-h-c)*ans)>(ans)*abs(h-c-(2*t-h-c)*(ans+2))){
                ans+=2L
            }
        }
        println("$ans")
    }
}