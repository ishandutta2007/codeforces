import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    for(x in 1..t) {
        var n = ni()
        var a = nal()
        var ans = 0L
        for (v in a) {
            var ct = 0L
            for (w in a) {
                if (w >= v) {
                    ct += 1
                }
            }
            ans = Math.max(ans, ct * v)
        }
        out.println(ans)
    }
}

val out = PrintWriter(System.out)

fun main() {
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