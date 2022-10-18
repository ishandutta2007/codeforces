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
        var x=ArrayList<Pair<Int,Int>>()
        for(i in 0..n-1){
            x.add(Pair(a[i],i+1))
        }
        x.sortWith(compareBy({it.first},{it.second}))
        var b=IntArray(n)
        b[0]=x[n-1].second
        var p=0
        var c=0
        for(j in 0..n-1){
            p+=x[j].first
            if(p>=n){
                c=j
                break
            }
            b[p]=x[j].second
        }
        for(j in c..n-1){
            for(k in 0..n-1){
                if(b[k]==0){
                    b[k]=x[j].second
                    break
                }
            }
        }
        cout(b.joinToString(" "))
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