import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val chains = jin.readLine().split(" ").map { it.toLong() }
        val ay = jin.readLine().split(" ").map { it.toLong() }.toLongArray()
        val by = jin.readLine().split(" ").map { it.toLong() }.toLongArray()
        for (j in 1 until n) {
            if (by[j] < ay[j] && j < n - 1) {
                ay[j + 1] = chains[j] - ay[j + 1] + 1L
                by[j + 1] = chains[j] - by[j + 1] + 1L
            }
            val a = min(ay[j], by[j])
            val b = max(ay[j], by[j])
            ay[j] = a
            by[j] = b
        }
        val dpForward = LongArray(n)
        var answer = 0L
        for (j in 1 until n) {
            if (j > 0) {
                dpForward[j] = 2L + (by[j] - ay[j])
                if (j > 1 && ay[j] < by[j]) {
                    dpForward[j] = max(dpForward[j], 2L + ay[j] - 1L + chains[j - 1] - by[j] + dpForward[j - 1])
                }
                answer = max(answer, dpForward[j] + chains[j] - 1L)
            }
        }
        println(answer)
    }
}