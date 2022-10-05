import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q, k) = jin.readLine().split(" ").map { it.toInt() }
    val ay = listOf(0) + jin.readLine().split(" ").map { it.toInt() } + listOf(0)
    val sums = LongArray(n + 1)
    for (j in 1..n) {
        sums[j] = sums[j - 1] + (ay[j + 1] - ay[j - 1] - 2).toLong()
    }
    val out = StringBuilder()
    for (j in 1..q) {
        val (l, r) = jin.readLine().split(" ").map { it.toInt() }
        out.appendln(if (l == r) {
            k - 1
        } else {
            sums[r - 1] - sums[l] + (k - ay[r - 1] - 1).toLong() + (ay[l + 1] - 2).toLong()
        })
    }
    print(out)
}