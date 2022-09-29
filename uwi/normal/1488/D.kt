//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class D {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var (n, s) = nal()
        var low = 0L
        var high = s + 1
        while(high - low > 1){
            var h = low + (high - low) / 2
            if(ok(h, n, s)){
                low = h
            }else{
                high = h
            }
        }
        out.println(low)
    }

    fun ok(h: Long, n: Long, s: Long) : Boolean {
        var rem = s
        var hh = h
        var nn = n
        while(nn > 0){
            if(hh == 1L){
                rem -= nn
                break
            }
            rem -= hh
            hh = (hh + 1) / 2
            nn--
        }
        return rem >= 0
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
fun main() = D().run()