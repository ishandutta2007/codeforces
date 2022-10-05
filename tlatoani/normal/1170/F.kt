import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val k = jin.nextLong()
    val pressures = Array(n) { jin.nextLong() }
    pressures.sort()
    val sums = LongArray(n + 1)
    for (i in 0 until n) {
        sums[i + 1] = sums[i] + pressures[i]
    }
    var j = 0
    var answer = Long.MAX_VALUE
    for (i in 0..n - m) {
        while (j <= i + (m / 2) && ((j - i).toLong() * pressures[j]) - (sums[j] - sums[i]) <= k) {
            j++
        }
        val gol = pressures[j - 1] + if (j <= i + (m / 2)) ((k - (((j - 1 - i).toLong() * pressures[j - 1]) - (sums[j - 1] - sums[i]))) / (j - i).toLong()) else 0L
        answer = min(answer,
                ((j - i).toLong() * gol) - (sums[j] - sums[i]) + (sums[i + m] - sums[j]) - ((i + m - j).toLong() * gol))
    }
    println(answer)
}