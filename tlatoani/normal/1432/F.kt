import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, d) = jin.readLine().split(" ").map { it.toInt() }
    val platforms = jin.readLine().split(" ").map { it.toInt() }
    if (platforms.sum() + ((m + 1) * (d - 1)) < n) {
        println("NO")
    } else {
        println("YES")
        val answer = IntArray(n)
        var j = 0
        for ((k, platform) in platforms.withIndex()) {
            j = min(j + d - 1, n - platforms.subList(k, m).sum())
            for (j2 in j until j + platform) {
                answer[j2] = k + 1
            }
            j += platform
        }
        println(answer.joinToString(" "))
    }
}