import java.util.*
import kotlin.math.min

val scanner = Scanner(System.`in`)

fun solve() {
    val n = scanner.nextLong()
    val k = scanner.nextLong()
    val x = scanner.nextLong()
    val y = scanner.nextLong()
    val a = Array(n.toInt()) { _ -> scanner.nextLong() }
    val mx = n * k
    var sum = a.sum()
    var ans = 0x1fffffffffffffff
    var cnt = 0L
    a.sort()
    for (i in n.toInt() - 1 downTo 0) {
        if (a[i] <= k) ans = min(ans, cnt)
        if (sum <= mx) ans = min(ans, cnt + y)
        cnt += x
        sum -= a[i]
    }
    ans = min(ans, cnt)
    println("$ans")
}

fun main() {
    val t = scanner.nextInt()
    for(i in 0 until t) solve()
}