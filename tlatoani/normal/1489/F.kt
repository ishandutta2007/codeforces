import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, k) = jin.readLine().split(" ").map { it.toInt() }
    val ay = jin.readLine().split(" ").map { it.toInt() }
    var upper = n
    var lower = 0
    while (upper > lower) {
        val mid = (upper + lower) / 2
        var boxesNeeded = 0
        var curr = k
        for (j in mid until n) {
            if (curr + ay[j] > k) {
                boxesNeeded++
                curr = 0
            }
            curr += ay[j]
        }
        if (boxesNeeded <= m) {
            upper = mid
        } else {
            lower = mid + 1
        }
    }
    println(n - upper)
}