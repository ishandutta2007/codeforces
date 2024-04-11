import java.lang.Math.*
import java.lang.reflect.Array
import java.util.*
import kotlin.collections.ArrayList

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { kotlin.system.exitProcess(0); }

// 101010101010101
// 5 3 -> 2 * 5 - 1
// 111111101
// 3 12
// 5 2
// 3 2
// 3 1
fun main() {
    var (n, m) = readii()
    var a = ArrayList<Pair<Int,Int>>()
    var sum1 = 0
    var nn = m
    var sum2 = 0
    var ans = IntArray(n)
    for (i in 0..n-1) {
        var (x, y) = readii()
        if(y == 2) {
            a.add(Pair<Int,Int>(i, x))
            sum2 += x
        } else {
            sum1 += x
            nn -= x
            ans[i] = nn + 1
        }
    }
    if(sum1 > m || sum2 > m) {
        println(-1)
        exit()
    }
    var dp = Array(a.size + 1) { IntArray(m + 1) }
    dp[0][0] = 1
    for (i in 0..a.size-1) {
        var p = a[i].second
        for (j in 0..m) {
            dp[i+1][j] = dp[i][j]
        }
        for (j in p..m) {
            if(dp[i][j-p] == 1) dp[i+1][j] = 1
        }
    }
    var mn = 1000000000
    var mi = -1
    for (i in 0..m) {
        if (dp[a.size][i] == 1) {
            if (max(sum2 - i, i) <= mn) {
                mn = max(sum2 - i, i)
                mi = i
            }
        }
    }
    var use = sum1
    if(a.size > 0) {
        if(mi == -1) {
            println(-1)
            exit()
        }
        use += max(sum2 - mi, mi) * 2 - 1
    }
    if(use > m) {
        println(-1)
        exit()
    }
    var cur = mi
    var p1 = 1
    var p2 = 2
    for (i in a.size-1 downTo 0) {
        val q = a[i].first
        val p = a[i].second
        if (cur >= p && dp[i][cur-p] == 1) {
            ans[q] = p1
            p1 += p * 2
            cur -= p
        } else {
            ans[q] = p2
            p2 += p * 2
        }
    }
    println(ans.joinToString(" "))
}