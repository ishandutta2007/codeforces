import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class E {
    fun solve() {
        var n = ni()
        var a = na()
        var b = na()

        a = a.sorted()
        b = b.sorted()

        var pre = mutableListOf(-2000000000)
        for(i in 0 until n){
            pre.add(Math.max(pre[pre.size-1], b[i] - a[i]))
        }

        var suf = mutableListOf(-2000000000)
        for(i in 0 until n){
            suf.add(Math.max(suf[suf.size-1], b[n-i] - a[n-1-i]))
        }

//        for(i in 0 until n+1){
//            Math.max(pre[i], suf[n-i])
//        }

        var m = ni()
        var q = na()
        for(v in q){
            var ind = Collections.binarySearch(a, v)
            if(ind < 0){
                ind = -ind-1
            }
            out.print(Math.max(Math.max(pre[ind], suf[n-ind]), b[ind] - v))
            out.print(" ")
        }
        out.println()

    }

    val out = PrintWriter(System.out)

    fun run() {
        tr(measureTimeMillis {
            solve()
            out.flush()
        })
    }

    fun nline() = readLine()!!
    fun ni() = nline().toInt()
    fun nl() = nline().toLong()
    fun nd() = nline().toDouble()
    fun nas() = nline().split(" ")
    fun na() = nas().map { it.toInt() }
    fun nal() = nas().map { it.toLong() }

    fun tr(vararg x: Any) = System.err.println(Arrays.deepToString(x))
}

// TODO
fun main() = E().run()