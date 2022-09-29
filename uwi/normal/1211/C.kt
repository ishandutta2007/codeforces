import java.io.PrintWriter
import java.util.*

fun solve() {
    val (n, K) = na()
    var abc: MutableList<IntArray> = mutableListOf()
    for(i in 0..n-1){
        val (a, b, c) = na()
        abc.add(intArrayOf(a, b, c))
    }
    var low = 0L
    var high = 0L
    for(u in abc){
        low += u[0]
        high += u[1]
    }
    if (K < low || K > high){
        out.println(-1)
    }else{
        abc.sortBy { it[2] }
        var rem = K - low
        var ans = 0L
        for(u in abc){
            ans += u[2].toLong()*u[0]
        }
        for(u in abc){
            val o = Math.min(rem, u[1].toLong()-u[0])
            ans += o.toLong()*u[2]
            rem -= o
        }
        out.println(ans)
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