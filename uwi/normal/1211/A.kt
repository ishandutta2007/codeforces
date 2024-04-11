import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = ni()
    val a = na()
    var ai : MutableList<IntArray> = mutableListOf()
    for(i in 0..n-1){
        ai.add(intArrayOf(a[i], i+1))
    }
    ai.sortBy { it[0] }
    var h :MutableList<Int> = mutableListOf()
    var cur = -1
    for(i in 0..n-1){
        if(ai[i][0] > cur){
            h.add(ai[i][1])
            cur = ai[i][0]
        }
    }
    if(h.size >= 3){
        out.println(h[0].toString() + " " + h[1].toString() + " " + h[2].toString())
    }else{
        out.println("-1 -1 -1")
    }
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