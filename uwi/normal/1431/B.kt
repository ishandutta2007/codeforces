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
    var s = nline()
    var vlen = 0
    var ans = 0
    for(c in s){
        if(c == 'w'){
            ans += 1
            ans += vlen/2
            vlen = 0
        }else{
            vlen += 1
        }
    }
    ans += vlen/2
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