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
        var(h,w,x,y)=readints()
        y=minOf(y,x*2)
        var ans=0
        while(h-->0){
            var s=readln()
            var i=0
            while(i<w){
                if(s[i]=='*'){
                    i++
                    continue
                }
                if(i!=w-1&&s[i+1]=='.'){
                    ans+=y
                    i+=2
                }else{
                    ans+=x
                    i+=1
                }
            }
        }
        println("$ans")
    }
}