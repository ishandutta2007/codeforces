import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val ay = jin.readLine().split(" ").map { it.toInt() }
    val lastIx = mutableMapOf<Int, Int>()
    for (j in 0 until n) {
        lastIx[ay[j]] = j
    }
    var answer = 1
    var k = 0
    for (j in 0 until n) {
        if (j > k) {
            answer *= 2
            answer %= 998244353
        }
        k = max(k, lastIx[ay[j]]!!)
    }
    println(answer)
}