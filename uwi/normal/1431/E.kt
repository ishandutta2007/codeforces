import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    for (x in 1..t) {
        go()
    }
}

fun go() {
    var n = ni()
    var a = na()
    var b = na()
    var ans = -1
    var arg = -1
    for(i in 0..n-1){
        var k = i
        var mi = 1000000007
        for(j in 0..n-1){
            mi = Math.min(mi, Math.abs(a[j] - b[k]))
            k = k + 1
            if(k >= n){
                k = 0
            }
        }
        if(mi > ans){
            ans = mi
            arg = i
        }
    }
    for(j in 0..n-1){
        out.print((j+arg)%n+1)
        out.print(" ")
    }
    out.println();
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