import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var n=readint()
        var a=readints()
        var b=readints()
        var ans=IntArray(n)
        var m=-1
        for(i in 0..n-1){
            var mn=1000000000
            for(j in 0..n-1){
                mn=min(mn,abs(a[j]-b[(i+j)%n]))
            }
            if(mn>m){
                m=mn
                for(j in 0..n-1){
                    ans[j]=(i+j)%n+1
                }
            }
        }
        cout(ans.joinToString(" "))
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