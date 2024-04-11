import java.io.PrintWriter
import java.util.*

fun go(a: LongArray) : Long {
    val n = a.size
    var cum = LongArray(n+1)
    var wcum = LongArray(n+1)
    for(i in 1..n){
        cum[i] = cum[i-1] + a[i-1].toLong()
        wcum[i] = wcum[i-1] + a[i-1].toLong() * (i-1)
    }
    var ret = Long.MAX_VALUE
    for(i in 0..n-1){
        ret = Math.min(ret, (i*cum[i]-wcum[i]) + (wcum[n]-wcum[i]-i*(cum[n] - cum[i])))
    }
    return ret
}

fun solve() {
    val (n, m, Q) = na()
    var mp: MutableList<IntArray> = mutableListOf()
    for(j in 1..n){
        mp.add(na().toIntArray())
    }
    var hol = LongArray(m)
    var ver = LongArray(n)
    for(i in 0..n-1){
        for(j in 0..m-1){
            hol[j] += mp[i][j].toLong()
            ver[i] += mp[i][j].toLong()
        }
    }

    out.print(go(hol) + go(ver))
    out.print(" ")
    for(z in 1..Q){
        var (r, c, w) = na()
        r -= 1
        c -= 1
        val de = w - mp[r][c]
        mp[r][c] += de
        hol[c] += de.toLong()
        ver[r] += de.toLong()

        out.print(go(hol) + go(ver))
        out.print(" ")
    }
    out.println();
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