//package kh6.p
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class A {
    fun solve() {
        var n = ni()
        var a = na()
        var ret = mutableListOf<Int>()
        outer@
        for(i in 0..n-1){
            for(j in i+1..n-1){
                if(a[i] == a[j])continue@outer
            }
            ret.add(a[i])
        }
        out.println(ret.size)
        for(v in ret){
            out.print("$v ")
        }
        out.println()
    }

    val out = PrintWriter(System.out)

    fun run() {
        tr(measureTimeMillis {
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

fun main() = A().run()