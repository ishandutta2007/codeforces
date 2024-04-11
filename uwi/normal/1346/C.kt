import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    for(i in 1..t){
        val (n, k, x, y) = na()
        var a = na()
        a = a.sorted()
        if(a[n-1] <= k){
            out.println(0)
            continue
        }
        var s: Long = 0L
        for(v in a){
            s += v
        }

        var ans = n.toLong() * x
        if(s <= n.toLong()*k){
            ans = Math.min(ans, y.toLong())
        }
        for(j in 0..n-1){
            if(a[n-1-j] <= k){
                ans = Math.min(ans, j.toLong()*x)
            }
            s -= a[n-1-j]
            if(s <= n.toLong()*k){
                ans = Math.min(ans, (j+1).toLong()*x+y)
            }
        }
        out.println(ans)
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