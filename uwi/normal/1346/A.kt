import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    for(i in 1..t){
        val (n, k) = na()
        val b = n/(1+k+k*k+k*k*k)
        out.print(b)
        out.print(" ")
        out.print(b*k)
        out.print(" ")
        out.print(b*k*k)
        out.print(" ")
        out.print(b*k*k*k)
        out.println()
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