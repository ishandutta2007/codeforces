import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val ay = jin.readLine().split(" ").map { it.toLong() }
    var answer = 0
    for (j in 0 until n) {
        var sum = 0L
        for (k in j - 2 downTo 0) {
            sum += ay[k + 1]
            if (sum > 2L * ay[j]) {
                break
            }
            if (ay[j] >= ay[k] && ay[j] xor ay[k] == sum) {
                answer++
            }
        }
        sum = 0L
        for (k in j + 2 until n) {
            sum += ay[k - 1]
            if (sum > 2L * ay[j]) {
                break
            }
            if (ay[j] > ay[k] && ay[j] xor ay[k] == sum) {
                answer++
            }
        }
    }
    println(answer)
}