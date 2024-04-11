//package kh6.p
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class E {
    fun solve() {
        var Q = ni()
        var ids = IntArray(200005)
        var l = 0
        var r = 0
        repeat(Q) {
            var (o, sind) = nline().split(" ")
            var ind = sind.toInt()
            if (o == "L") {
                l--
                ids[ind] = l
            }else if(o == "R"){
                ids[ind] = r
                r++
            }else{
                out.println(kotlin.math.min(ids[ind]-l, r-ids[ind]-1))
            }
        }
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
fun main() = E().run()