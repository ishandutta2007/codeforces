//package kh8
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class A {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var s = nline()
        var l = (">" in s)
        var g = ("<" in s)
        if(!l && !g){
            out.println("=")
        }else if(l && !g){
            out.println(">")
        }else if(!l && g){
            out.println("<")
        }else{
            out.println("?")
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

    fun tr(vararg x: Any) = System.err.println(Arrays.deepToString(x))
}

// TODO
fun main() = A().run()