//package kh6.p
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class C {
    fun solve() {
        var n = ni()
        var s = nline()
        var t = mutableListOf<Char>()
        for(c in s){
            if(c == 'x'){
                if(t.size >= 2 && t[t.size-1] == 'x' && t[t.size-2] == 'x'){
                    continue
                }
            }
            t.add(c)
        }
        out.println(n-t.size)
    }

    val out = PrintWriter(System.out)

    fun run() {
        tr(measureTimeMillis {
            // TODO
//            repeat(ni()) {
//                solve()
//            }
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
fun main() = C().run()