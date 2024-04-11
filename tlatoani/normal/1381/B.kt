import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ps = jin.readLine().split(" ").map { it.toInt() }
        val dp = BooleanArray(n + 1)
        dp[0] = true
        val seen = BooleanArray((2 * n) + 1)
        var m = 2 * n
        var curr = 0
        for (p in ps.reversed()) {
            curr++
            seen[p] = true
            if (p == m) {
                for (j in n downTo curr) {
                    dp[j] = dp[j] || dp[j - curr]
                }
                curr = 0
                while (seen[m]) {
                    m--
                }
            }
        }
        out.appendln(if (dp[n]) "YES" else "NO")
    }
    print(out)
}