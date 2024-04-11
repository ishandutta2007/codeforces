//package a

import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    for(z in 1..t){
        var (ab, ac) = na()
        val a = Math.min(ab, ac)-1
        val b = ab-a
        val c = ac-a
        out.printf("%d %d %d\n", a, b, c)
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