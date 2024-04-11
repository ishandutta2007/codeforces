import java.io.PrintWriter
import java.lang.Math.min
import java.util.*

fun solve() {
    val t = ni()
    for(i in 1..t){
        go()
    }
}

fun go() {
    var (n, K) = na()
    var a = na()
    var ai: MutableList<IntArray> = mutableListOf()
    for(i in 0..n-1){
        ai.add(intArrayOf(a[i], i, 0))
    }
    ai.sortBy{ it[0] }
    for(i in n-2 downTo 0){
        ai[i][2] = min(K, ai[n-1][0] - ai[i][0] - (n-1-i))
        K -= ai[i][2]
    }
    if(K > 0){
        val plus = (K+n-1)/n
        for(i in 0..n-1){
            ai[i][2] += K/n
            if(n-i <= K%n){
                ai[i][2] += 1
            }
        }
    }
    ai.sortBy{ it[1] }
    for(i in 0..n-1){
        out.print(ai[i][2])
        out.print(" ")
    }
    out.println()

//    out.println(ai)
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