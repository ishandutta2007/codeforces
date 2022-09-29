//package kh6.p
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis
import kotlin.math.*

class B {
    fun solve() {
        var (n, a, b) = nal()
        out.println(min(n*a, n/2*b + n%2*a))
    }

    val out = PrintWriter(System.out)

    fun run() {
        tr(measureTimeMillis {
            repeat(ni()) {
                solve()
            }
//            solve()
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

    fun tr(x: Any) = System.err.println(x)
    fun tr(x: IntArray) = System.err.println(Arrays.toString(x))
    fun tr(x: Array<Any>) = System.err.println(Arrays.deepToString(x))
}

fun main() = B().run()