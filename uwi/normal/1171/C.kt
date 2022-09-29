//package c

import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = nl()
    for(z in 1..n){
        val s = nline()
        val t = s.toCharArray()
        t.sort()
        if(t[0] == t[t.size-1]){
            out.println(-1)
        }else{
            out.println(String(t))
        }
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