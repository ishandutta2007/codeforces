//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class B {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var (n,k) = na()
        var s = nline()
        var h = 0
        var z = 0
        var o = 0
        for(c in s){
            if(c == '('){
                h++
            }else{
                h--
                if(h == 0){
                    z++
                }else{
                    o++
                }
            }
        }
        out.println(z + kotlin.math.min(o, k))
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
fun main() = B().run()