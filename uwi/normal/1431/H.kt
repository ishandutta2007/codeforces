import java.io.PrintWriter
import java.util.*

fun solve() {
    var (n, m, K) = na()
    var a = nal()
    var b = nal()
    var c = mutableListOf<LongArray>()
    for(i in 0..n-1){
        c.add(nal().toLongArray())
    }
    for(i in 0..n-1){
        for(j in 0..m-1){
            if(i-1 >= 0){
                c[i][j] = Math.max(c[i][j], c[i-1][j])
            }
            if(j-1 >= 0){
                c[i][j] = Math.max(c[i][j], c[i][j-1])
            }
        }
    }
    var ans = 10000000000000000L
    for(hit in 0..n+m+1){
        var st = 0L
        var x = 0L
        var p = 0
        var q = 0
        var hitv = -1L
        var xst = 0
        while(true) {
            while (p < n && a[p] <= x) {
                p++
            }
            while (q < m && b[q] <= x) {
                q++
            }
            if(p == n && q == m){
                break
            }

            if(xst == hit) {
                hitv = c[p - 1][q - 1]
            }
            var pl = c[p-1][q-1]
            if(c[p-1][q-1] == hitv){
                pl = pl + K.toLong()
            }
            if(hitv >= 0 && pl > hitv && hitv + K.toLong() > pl){
                pl = hitv + K.toLong()
            }

            var ne = 100000000000000L
            if(p < n){
                ne = Math.min(ne, a[p]-x)
            }
            if(q < m){
                ne = Math.min(ne, b[q]-x)
            }
            st = st + (ne+pl-1)/pl
            x += (ne+pl-1)/pl*pl
            xst++
//            out.print(st)
//            out.print(" ")
//            out.print(x)
//            out.print(" ")
//            out.println(xst)
        }
        ans = Math.min(ans, st)
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