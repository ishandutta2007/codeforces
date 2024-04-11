import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    var dp = IntArray(26)
    val present = BooleanArray(26)
    for (j in 1..n) {
        val new = IntArray(26) { if (present[it]) 1 else 0 }
        val s = jin.readLine().map { it - 'a' }
        var last = -1
        var curr = 0
        for (chara in s) {
            if (chara == last) {
                curr++
            } else {
                last = chara
                curr = 1
            }
            new[chara] = max(new[chara], curr)
        }
        if (s.all { it == s[0] }) {
            new[s[0]] = max(new[s[0]], ((dp[s[0]] + 1) * (s.size + 1)) - 1)
        } else {
            var k1 = 0
            while (s[k1] == s[0]) {
                k1++
            }
            var k2 = s.size - 1
            while (s[k2] == s.last()) {
                k2--
            }
            if (s[0] == s.last()) {
                if (present[s[0]]) {
                    new[s[0]] = max(new[s[0]], k1 + s.size - k2)
                }
            } else {
                if (present[s[0]]) {
                    new[s[0]] = max(new[s[0]], k1 + 1)
                }
                if (present[s.last()]) {
                    new[s.last()] = max(new[s.last()], s.size - k2)
                }
            }
        }
        for (chara in s) {
            present[chara] = true
        }
        dp = new
    }
    println(dp.max())
}