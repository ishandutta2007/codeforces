import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = ni()
    var a = na()
    var mx = -1
    var arg = -1
    for(i in 0..n-1){
        if(a[i] >= mx){
            mx = a[i]
            arg = i
        }
    }
    out.println(n.toLong()*mx+arg-n+1)
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