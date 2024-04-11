import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    outer@
    for(i in 1..t){
        val (n, m) = na()
        var es: MutableList<IntArray> = mutableListOf()
        for(j in 1..m){
            val (f, q, w) = na()
            es.add(intArrayOf(f-1, q-1, w))
        }

        var h = IntArray(n)
        for(e in es){
            h[e[0]] = Math.max(h[e[0]], e[2])
            h[e[1]] = Math.max(h[e[1]], e[2])
        }

        for(e in es){
            if(Math.min(h[e[0]], h[e[1]]) != e[2]){
                out.println("NO")
                continue@outer
            }
        }

        out.println("YES")
        for(x in h){
            out.print(x)
            out.print(" ")
        }
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