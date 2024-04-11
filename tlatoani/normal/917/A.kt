import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val s = jin.nextLine()
    val n = s.length
    val dp = Array(n + 1) { BooleanArray(n + 1) }
    val left = Array(n + 1) { BitSet(n + 1) }
    val right = Array(n + 1) { BitSet(n + 1) }
    var answer = 0
    for (l in n - 1 downTo 0) {
        for (r in 1..n) {
            if (s[l] != ')' && s[r - 1] != '(' && (dp[l + 1][r - 1] || r == l + 2)) {
                dp[l][r] = true
            } else if (right[l].intersects(left[r])) {
                dp[l][r] = true
            }
            if (dp[l][r]) {
                answer++
                right[l].set(r)
                left[r].set(l)
            }
        }
    }
    println(answer)
}