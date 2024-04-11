//package b

import java.io.PrintWriter
import java.util.*

fun solve() {
    var t = ni()
    val a = na()
    var max1 = 0
    var max2 = 0
    var ct = 0
    for(v in a){
        if(v < max2){
            ct++
        }
        if(v > max1){
            max2 = max1
            max1 = v
        }else if(v > max2){
            max2 = v
        }
    }
    out.println(ct)
}

val out = PrintWriter(System.out)

fun main(args: Array<String>) {
    solve()
    out.flush()
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