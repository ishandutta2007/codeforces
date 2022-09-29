import java.io.PrintWriter
import java.util.*

fun solve() {
    val t = ni()
    outer@
    for(i in 1..t){
        val n = ni()
        var ab: MutableList<Pair<Int, Int>> = mutableListOf()
        for(j in 1..n) {
            var (x, y) = na()
            ab.add(Pair(x, y))
        }
        for(j in 0..n-1){
            var ct = 0
            for(k in 0..n-1){
                if(ab[k].first <= ab[j].first && ab[j].first <= ab[k].second){
                    ct += 1
                }
            }
            if(ct == 1){
                out.println(ab[j].first)
                continue@outer
            }
        }
        for(j in 0..n-1){
            var ct = 0
            val x = ab[j].second + 1
            for(k in 0..n-1){
                if(ab[k].first <= x && x <= ab[k].second){
                    ct += 1
                }
            }
            if(ct == 1){
                out.println(x)
                continue@outer
            }
        }
        out.println(-1)
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