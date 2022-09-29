//package kh8
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class B {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var n = ni()
        var (a, va) = na()
        var (c, vc) = na()
        var b = ni()
        out.println(Math.max(va, vc - (c-b)))
    }

    val out = PrintWriter(System.out)

    fun run() {
        tr(measureTimeMillis {
            solve()
            out.flush()
        })
    }

    fun nline() = readLine()!!
    fun ni() = nline().toInt()
    fun nl() = nline().toLong()
    fun nd() = nline().toDouble()
    fun nas() = nline().split(" ")
    fun na() = nas().map { it.toInt() }
    fun nal() = nas().map { it.toLong() }

    fun tr(vararg x: Any) = System.err.println(Arrays.deepToString(x))
}

// TODO
fun main() = B().run()