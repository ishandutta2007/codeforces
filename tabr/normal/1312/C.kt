import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var (n,k)=readints()
        var a=readlongs()
        var ans="YES"
        var t=IntArray(100)
        for(i in 0..n-1){
            var c=0
            while(a[i]!=0L){
                if(a[i]%k==1L){
                    t[c]++
                }else if(a[i]%k!=0L){
                    ans="NO"
                }
                a[i]=a[i]/k
                c++
            }
        }
        if(t.max()!!>1){
            ans="NO"
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