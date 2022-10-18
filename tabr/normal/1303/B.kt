import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var(n,g,b)=readlongs()
        var hi=3e18.toLong()
        var lo=n-1
        while(hi-lo>1){
            var mid=(hi+lo)/2
            var x=min(g,mid%(g+b))+mid/(g+b)*g
            if(x>=(n+1)/2){
                hi=mid
            }else{
                lo=mid
            }
        }
        cout(hi)
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