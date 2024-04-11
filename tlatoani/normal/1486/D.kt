import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = jin.readLine().split(" ").map { it.toInt() }
    val ay = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    var upper = ay.max()!!
    var lower = ay.min()!!
    val sums = IntArray(n + 1)
    while (upper > lower) {
        val mid = (upper + lower + 1) / 2
        var exists = false
        var minimo = n
        for (j in 1..n) {
            sums[j] = sums[j - 1]
            if (ay[j] >= mid) {
                sums[j]++
            } else {
                sums[j]--
            }
            if (j >= k) {
                minimo = min(minimo, sums[j - k])
                exists = exists || sums[j] > minimo
            }
        }
        if (exists) {
            lower = mid
        } else {
            upper = mid - 1
        }
    }
    println(upper)
}