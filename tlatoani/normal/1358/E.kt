import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val profits = jin.readLine().split(" ").map { it.toLong() } + listOf(0L)
    val stable = jin.readLine().toLong()
    var curr = profits.sum()
    var m = curr
    for (k in n downTo (n + 1) / 2) {
        if (m + ((k - ((n + 1) / 2)).toLong() * stable) > 0L) {
            println(k)
            return
        }
        curr -= profits[n - k]
        curr += stable
        m = min(m, curr)
    }
    println(-1)
}