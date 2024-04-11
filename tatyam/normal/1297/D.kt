import java.io.PrintWriter
import java.util.*
import kotlin.math.*
const val INF = 0x3fffffff

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)


    val t = sc.nextLong()
    for (i_ in 0 until t) {
        val n = sc.nextInt()
        var k = sc.nextLong()
        val a = Array(n){
            sc.nextLong()
        }
        val b = Array(n){ it }
        b.sortBy{ -a[it] }
        val ans = LongArray(n)
        for (i_ in 0 until n - 1) {
            val i = b[i_]
            val j = b[i_ + 1]
            var diff = a[i] - a[j] - 1
            if (diff > k) {
                diff = k
                k = 0
            }
            else k -= diff
            ans[j] += diff
            a[j] += diff

        }
        for (i_ in 0 until n) {
            val i = b[i_]
            ans[i] += k / n + (if (k % n > i_) 1 else 0)
        }
        for (i in ans) pw.print("$i ")
        pw.println()
    }

    pw.flush()
}