import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.random.Random

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val likes = Array(n) { jin.readLine() }
    val random = Random(System.currentTimeMillis())
    var answer = CharArray(m) { '0' }
    repeat(20) {
        val r = random.nextInt(n)
        val positions = IntArray(m) { -1 }
        var p = 0
        for (j in 0 until m) {
            if (likes[r][j] == '1') {
                positions[j] = p
                p++
            }
        }
        val dp = IntArray(1 shl p)
        for (trader in likes) {
            var mask = 0
            for (j in 0 until m) {
                if (trader[j] == '1' && positions[j] != -1) {
                    mask += 1 shl positions[j]
                }
            }
            dp[mask]++
        }
        for (j in 0 until p) {
            for (mask in 0 until (1 shl p)) {
                if (mask and (1 shl j) == 0) {
                    dp[mask] += dp[mask + (1 shl j)]
                }
            }
        }
        var here = 0
        for (mask in 0 until (1 shl p)) {
            if (2 * dp[mask] >= n && Integer.bitCount(mask) >= Integer.bitCount(here)) {
                here = mask
            }
        }
        if (Integer.bitCount(here) >= answer.count { it == '1' }) {
            for (j in 0 until m) {
                answer[j] = if (positions[j] != -1 && here and (1 shl positions[j]) != 0) '1' else '0'
            }
        }
    }
    println(answer)
}