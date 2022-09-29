//package kh6.p
import java.io.PrintWriter
import java.util.*
import kotlin.reflect.KMutableProperty
import kotlin.system.measureTimeMillis

class F {
    fun solve() {
        var (n, m, K) = na()
        var a = na()
        var low = -1
        var high = n+1
        while(high - low > 1){
            var h = low + (high-low)/2
            if(ok(m, K, a.slice(h until n))){
                high = h
            }else{
                low = h
            }
        }
        out.println(n - high)
    }

    fun ok(m: Int, K: Int, a: List<Int>): Boolean {
        var rb = m-1
        var rm = K
        for(v in a){
            if(v > K)return false
            if(v > rm){
                rm = K
                rb--
            }
            rm -= v
        }
        return rb >= 0
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

    fun tr(x: Any) = System.err.println(x)
    fun tr(x: IntArray) = System.err.println(Arrays.toString(x))
    fun tr(x: Array<Any>) = System.err.println(Arrays.deepToString(x))
}

// TODO
fun main() = F().run()