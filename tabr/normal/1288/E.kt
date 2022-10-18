import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var(n,m)=readints()
    var a=readints()
    var x=IntArray(n){it+1}
    var y=IntArray(n){it+1}
    var ft=fenwick(n+m)
    for(i in 0..n-1){
        ft.add(i,1)
    }
    var pre=IntArray(n){n-1-it}
    for(i in 0..m-1){
        x[a[i]-1]=1
        y[a[i]-1]=max(y[a[i]-1],n+1-ft.get(pre[a[i]-1]))
        ft.add(pre[a[i]-1],-1)
        pre[a[i]-1]=i+n
        ft.add(n+i,1)
    }
    for(i in 0..n-1){
        y[i]=max(y[i],n+1-ft.get(pre[i]))
    }
    for(i in 0..n-1){
        cout("${x[i]} ${y[i]}")
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

class fenwick(_n: Int) {
    val n = _n
    val node = IntArray(n)
    fun add(_x: Int, v: Int) {
        var x = _x
        while (x < n) {
            node[x] += v
            x = (x or (x + 1))
        }
    }
    fun get(_x: Int): Int {
        var x = _x
        var v = 0
        while (x >= 0) {
            v += node[x]
            x = (x and (x + 1)) - 1
        }
        return v
    }
}