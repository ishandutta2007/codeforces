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
        var n=s.length
        var t=n
        for(i in 0..n-1){
            if(s[i]=='1'){
                t--
            }
        }
        for(i in 0..n-1){
            if(s[i]=='1'){
                break
            }
            t--
        }
        for(i in n-1 downTo 0){
            if(s[i]=='1'){
                break
            }
            t--
        }
        cout(max(0,t))
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