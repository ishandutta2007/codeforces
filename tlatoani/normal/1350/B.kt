import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val array = arrayOf(0) + jin.readLine().split(" ").map { it.toInt() }
        val dp = IntArray(n + 1)
        for (j in 1..n) {
            for (k in 1..320) {
                if (j % k == 0) {
                    if (array[j] > array[k]) {
                        dp[j] = max(dp[j], dp[k])
                    }
                    if (array[j] > array[j / k]) {
                        dp[j] = max(dp[j], dp[j / k])
                    }
                }
            }
            dp[j]++
        }
        println(dp.max())
    }
}