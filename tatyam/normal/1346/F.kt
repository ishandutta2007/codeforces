import java.util.*
import kotlin.math.*

val scanner = Scanner(System.`in`)
val INF = 0x3fffffff

fun center(a : MutableList<Long>) : Long {
    val n = a.size
    val s = MutableList(n + 1) { 0L }
    for (i in 1..n) s[i] = s[i - 1] + a[i - 1]
    var cen = 0
    for (i in 1..n) if(s[i] * 2 >= s.last()) {
        cen = i - 1
        break
    }
    var ans = 0L
    for (i in 0 until n) ans += a[i] * abs(i - cen)
    return ans
}

fun main() {
    val n = scanner.nextInt()
    val m = scanner.nextInt()
    val q = scanner.nextInt()
    val x = MutableList(n) { 0L }
    val y = MutableList(m) { 0L }
    val a = MutableList(n) { MutableList(m) { scanner.nextLong() } }
    for (i in 0 until n) for (j in 0 until m) {
        x[i] += a[i][j]
        y[j] += a[i][j]
    }
    print("${center(x) + center(y)} ")
    for (i in 1..q) {
        val i = scanner.nextInt() - 1
        val j = scanner.nextInt() - 1
        val z = scanner.nextLong()
        x[i] -= a[i][j]
        y[j] -= a[i][j]
        a[i][j] = z
        x[i] += a[i][j]
        y[j] += a[i][j]
        print("${center(x) + center(y)} ")
    }
    println()
}