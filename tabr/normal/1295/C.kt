import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var s=readln()
        var t=readln()
        var n=s.length
        var st=Array(26){TreeSet<Int>()}
        for(i in 0..n-1){
            st[s[i]-'a'].add(i)
            st[s[i]-'a'].add(i+n)
        }
        var ans=1
        var cur=-1
        for(c in t){
            var k=c-'a'
            cur=st[k].higher(cur)?:-1
            if(cur==-1){
                ans=cur
                break
            }
            if(cur>=n){
                cur-=n
                ans++
            }
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