import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val seen = BooleanArray(n + 1)
    val rem = IntArray(n + 1)
    val books = jin.readLine().split(" ").map { it.toInt() }
    for (color in books) {
        rem[color]++
    }
    var mexico = 0
    var curr = 0
    val dp = IntArray(n + 1)
    for (color in books) {
        mexico = max(mexico, curr + rem[color])
        if (!seen[color]) {
            seen[color] = true
            dp[color] = curr + rem[color]
        }
        rem[color]--
        if (rem[color] == 0) {
            curr = max(curr, dp[color])
        }
    }
    println(n - mexico)
}