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
    var tt=readint()
    while(tt-->0){
        var n=readint()
        var a=readints()
        var k=a.max()
        var id=-1
        for(i in 0..n-1){
            if(a[i]==k){
                if(i!=0&&a[i-1]!=k){
                    id=i+1
                    break
                }else if(i!=n-1&&a[i+1]!=k){
                    id=i+1
                    break
                }
            }
        }
        println("$id")
    }
}