import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val s = mutableListOf<Int>()
    var last = '2'
    var amt = 0
    for (chara in jin.next()) {
        if (chara == last) {
            amt++
        } else {
            if (amt != 0) {
                s.add(amt)
            }
            amt = 1
            last = chara
        }
    }
    s.add(amt)
    if (s.size % 2 == 0) {
        s.add(0)
    }
    //println("s = $s")
    val a = longArrayOf(0L) + LongArray(n) { jin.nextLong() }
    for (j in 1..n) {
        for (k in 1..j) {
            a[j] = max(a[j], a[k] + a[j - k])
        }
    }
    val m = s.size
    val dp = Array(m) { Array(m) { LongArray(n + 1) { -1L } } }
    for (j in m - 1 downTo 0) {
        for (k in j until m) {
            if ((j + k) % 2 != 0) {
                continue
            }
            if (j == k) {
                dp[j][k][s[j]] = 0L
                dp[j][k][0] = a[s[j]]
                continue
            }
            dp[j][k][s[j] + s[k]] = dp[j + 1][k - 1][0]
            dp[j][k][0] = dp[j + 1][k - 1][0] + a[s[j] + s[k]]
            //println("dp[$j][$k][${s[j] + s[k]}] = ${dp[j][k][s[j] + s[k]]}")
            //println("dp[$j][$k][0] = ${dp[j][k][0]}")
            for (lambda in s[k]..n) {
                var l = j
                while (l < k) {
                    if (dp[j][l][lambda - s[k]] != -1L) {
                        dp[j][k][lambda] = max(dp[j][k][lambda], dp[j][l][lambda - s[k]] + dp[l + 1][k - 1][0])
                    }
                    l += 2
                }
                if (dp[j][k][lambda] != -1L) {
                    dp[j][k][0] = max(dp[j][k][0], dp[j][k][lambda] + a[lambda])
                }
            }
        }
    }
    println(dp[0][m - 1][0])
}