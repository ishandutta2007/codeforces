//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class C {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var (n,x,y) = na()
        if(x > y){
            var d = x
            x = y
            y = d
        }

        var ans = 999999999
        for(i in x..y-1){
            var lx = x-1
            var rx = i-x
            var ly = y-(i+1)
            var ry = n-y
            var v = kotlin.math.max(
                    kotlin.math.min(lx, rx) * 2 + kotlin.math.max(lx, rx),
                    kotlin.math.min(ly, ry) * 2 + kotlin.math.max(ly, ry)
            )
//            tr(i, lx, rx, ly, ry, v)
            ans = kotlin.math.min(v, ans)
        }
        out.println(ans)
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
fun main() = C().run()