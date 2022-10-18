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
        if(n==1){
            println("1")
            continue
        }
        var a=ArrayList<Int>()
        a.add(1)
        for(i in 1..n-1){
            if(s[i]==s[i-1]){
                a[a.size-1]++
            }else{
                a.add(1)
            }
        }
        var t=0
        var j=0
        for(i in 0..a.size-1){
            j=maxOf(i,j)
            if(a[i]==0){
                continue
            }else if(a[i]>1){
                t++
            }else{
                while(j!=a.size&&a[j]<=1){
                    j++
                }
                if(j==a.size){
                    if(i!=a.size-1){
                        a[i+1]=0
                    }
                    t++
                }else if(a[j]>1){
                    a[j]--
                    t++
                }
            }
        }
        println("$t")  
    }
}