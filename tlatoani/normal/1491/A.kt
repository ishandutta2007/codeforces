import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val ay = (listOf(0) + jin.readLine().split(" ").map { it.toInt() }).toIntArray()
    var sum = ay.sum()
    val out = StringBuilder()
    for (j in 1..q) {
        val (t, k) = jin.readLine().split(" ").map { it.toInt() }
        if (t == 1) {
            sum -= ay[k]
            ay[k] = 1 - ay[k]
            sum += ay[k]
        } else {
            out.appendln(if (k <= sum) 1 else 0)
        }
    }
    print(out)
}