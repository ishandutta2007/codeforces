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
    var n = ni()
    var a = na()
    var ai = IntArray(n)
    for(i in 0..n-1){
        ai[i] = (a[i] shl 10) or (i+1)
    }
    ai.sort()

    var q = n-2
    var ans = IntArray(n)
    ans[0] = ai[n-1] and 1023
    var r = 1
    for(p in 0..n-1){
        var v: Int = (ai[p] shr 10) - 1
        if(q-v >= p) {
            for (i in q - v + 1..q) {
                ans[r] = ai[i] and 1023
                r = r + 1
            }
            q = q - v
            ans[r] = ai[p] and 1023
            r = r + 1
        }else{
            for(i in p..q){
                ans[r] = ai[i] and 1023
                r = r + 1
            }
            break
        }
    }

    for(i in 0..n-1) {
        out.print(ans[i])
        out.print(" ")
    }
    out.println()
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