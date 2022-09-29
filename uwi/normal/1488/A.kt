//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class A {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var (x, y) = nal()
        var ans = 9999999999L
        var cur = 0
        while(true){
            ans = kotlin.math.min(ans, cur+y)
            var pp = x
            while(pp*10 <= y){
                pp *= 10
            }
            if(pp <= y){
                y -= pp
                cur++
            }else{
                break
            }
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
fun main() = A().run()