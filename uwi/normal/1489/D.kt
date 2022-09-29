//package kh6.p
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class D {
    fun solve() {
        var n = ni()
        var list = mutableListOf<String>()
        for(i in 0 until n){
            list.add(nline())
        }
        list.sortBy { it.length }
        for(i in 0 until n){
            for(j in 0 until i){
                if(!list[i].contains(list[j])){
                    out.println("NO")
                    return
                }
            }
        }

        out.println("YES")
        list.forEach(out::println)
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
fun main() = D().run()