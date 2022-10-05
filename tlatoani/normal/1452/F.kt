import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val amt = jin.readLine().split(" ").map { it.toLong() }.toLongArray()
    val out = StringBuilder()
    for (pie in 1..q) {
        val (a, b, c) = jin.readLine().split(" ").map { it.toLong() }
        val k = b.toInt()
        if (a == 1L) {
            amt[k] = c
        } else {
            var rem = c
            var potential = 0L
            for (j in 0..k) {
                rem -= amt[j]
                potential += ((1L shl j) - 1L) * amt[j]
            }
            var answer = 0L
            for (j in k + 1 until n) {
                if (rem <= 0L) {
                    break
                }
                val pow2 = 1L shl (j - k)
                val x = min(rem / pow2, amt[j])
                rem -= pow2 * x
                answer += (pow2 - 1L) * x
                potential += ((1L shl k) - 1) * pow2 * x
                if (amt[j] > x) {
                    if (potential >= rem) {
                        answer += rem
                        rem = 0L
                    } else {
                        var y = (rem - potential + (1L shl k) - 1L) / (1L shl k)
                        var cost = rem - y
                        var t = y
                        for (z in 0 until j - k) {
                            t += t and 1L
                            t /= 2L
                            cost += t
                        }
                        while (y + (y and -y) <= rem) {
                            y += y and -y
                            cost--
                        }
                        answer += cost
                        rem = 0L
                    }
                }
            }
            if (rem in 0L..potential) {
                answer += rem
                rem = 0L
            }
            out.appendln(if (rem <= 0L) answer else -1L)
        }
    }
    print(out)
}

/*
6 1
0 1 0 0 1 0
2 1 5

 */