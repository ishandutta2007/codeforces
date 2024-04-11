import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var (a,m)=readlongs()
        var g=gcd(a,m)
        var n=m/g
        var ans=n
        for(i in 2L..1000000L){
            if(i*i>n){
                continue
            }
            if(n%i==0L){
                ans-=ans/i
            }
            while(n%i==0L){
                n/=i
            }
        }
        if(n!=1L){
            ans-=ans/n
        }
        cout(ans)
    }
    print(output)
}

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendln(s)
fun cout(s: Int) = output.appendln(s.toString())
fun cout(s: Long) = output.appendln(s.toString())

fun gcd(a: Long, b: Long): Long {
    if(b == 0L) return a
    return gcd(b, a % b)
}