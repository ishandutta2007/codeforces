import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    for (x in 1..t) {
        go()
    }
}

fun go()
{
    var (n, k) = na()
    var a = na()
    var ans = 0L
    for(b in 1..n){
        var bu = b*k
        if(bu <= n){
            var s = 0L
            for(i in n-1-bu+1..n-1-bu+b){
                s += a[i]
            }
            ans = Math.max(ans, s)
        }
    }
    out.println(ans)
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