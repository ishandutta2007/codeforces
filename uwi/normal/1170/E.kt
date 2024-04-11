//package e

import java.io.PrintWriter
import java.util.*
import java.util.Arrays.binarySearch

fun solve() {
    val (n, m) = na()
    val a = na()
    var cum = IntArray(n+1)
    for(i in 0..n-1){
        cum[i+1] = cum[i] + a[i]
    }
    val q = ni()
    for(z in 1..q){
        val cl = na()
        var left = 0
        var cur = 0
        var ok = false
        for(i in 1..cl.size-1){
            val cha = cl[i] - left - 1
            var ind = binarySearch(cum, cum[cur] + cha)
            if(ind < 0)ind = -ind-2
            cur = ind
            if(cur >= n){
                ok = true
                break
            }
            left = cl[i]
        }
        if(!ok){
            val cha = m+1 - left - 1
            var ind = binarySearch(cum, cum[cur] + cha)
            if(ind < 0)ind = -ind-2
            cur = ind
            if(cur >= n){
                ok = true
            }
        }
        out.println(if(ok){ "YES"} else {"NO"})
    }
}

val out = PrintWriter(System.out)

fun main(args: Array<String>) {
    solve()
    out.flush()
}

fun nline() = readLine()!!
fun ni() = nline().toInt()
fun nl() = nline().toLong()
fun nd() = nline().toDouble()
fun nas() = nline().split(" ")
fun na() = nas().map { it.toInt() }
fun nal() = nas().map { it.toLong() }

fun tr(x: Any) = System.err.println(x)
fun tr(x: IntArray) = System.err.println(Arrays.toString(x))
fun tr(x: Array<Any>) = System.err.println(Arrays.deepToString(x))