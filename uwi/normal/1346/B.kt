import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    for(i in 1..t){
        var (n, k1, k2) = na()
        k2 = Math.min(k2, 2*k1)
        val s = nline()
        var re = 0
        var ans = 0
        for(j in 0..n-1){
            if(s[j] == '0') {
                ans += re/2 * k2
                ans += re%2 * k1
                re = 0
            }else{
                re += 1
            }
        }
        ans += re/2 * k2
        ans += re%2 * k1
        re = 0
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