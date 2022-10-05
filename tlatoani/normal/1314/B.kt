import java.lang.Exception
import java.util.*
import kotlin.math.max

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val k = line.substring(six + 1).toInt()
    val isFavorite = BooleanArray(1 shl n)
    if (k != 0) {
        val tokenizer = StringTokenizer(readLine()!!)
        for (j in 1..k) {
            isFavorite[tokenizer.nextToken().toInt() - 1] = true
        }
    }
    val dp = Array(1 shl (n - 1)) { IntArray(4) { -1 } }
    for (e in 0 until n) {
        try {
            val b = 1 shl e
            val b2 = 1 shl (e - 1)
            for (ji in 0 until (1 shl (n - e - 1))) {
                val j = ji * b
                if (e == 0) {
                    if (isFavorite[2 * j] && isFavorite[(2 * j) + 1]) {
                        dp[j][3] = 1
                    } else if (isFavorite[2 * j] || isFavorite[(2 * j) + 1]) {
                        dp[j][1] = 1
                        dp[j][2] = 1
                    } else {
                        dp[j][0] = 0
                    }
                } else {
                    val new = IntArray(4) { -1 }
                    for (mask1 in 0..3) {
                        if (dp[j][mask1] == -1) {
                            continue
                        }
                        for (mask2 in 0..3) {
                            if (dp[j + b2][mask2] == -1) {
                                continue
                            }
                            var res = dp[j][mask1] + dp[j + b2][mask2]
                            if (mask1 / 2 == 1 || mask2 / 2 == 1) {
                                res++
                            }
                            if (mask1 % 2 == 1 || mask2 % 2 == 1) {
                                res++
                            }
                            for (x in 0..1) {
                                val winner1 = if (x == 0) (mask1 / 2) else (mask2 / 2)
                                val loser1 = if (x == 1) (mask1 / 2) else (mask2 / 2)
                                for (y in 0..1) {
                                    val winner2 = if (y == 0) (mask1 % 2) else (mask2 % 2)
                                    for (z in 0..1) {
                                        val winner3 = if (z == 0) loser1 else winner2
                                        val mask = (2 * winner1) + winner3
                                        new[mask] = max(new[mask], res + (loser1 or winner2))
                                    }
                                }
                            }
                        }
                    }
                    dp[j] = new
                }
                //println("e = $e, j = $j, dp = ${dp[j].contentToString()}")
            }
        } catch (e: Exception) {
            println(-1)
            return
        }
    }
    var answer = 0
    for (mask in 0..3) {
        if (dp[0][mask] != -1) {
            answer = max(answer, dp[0][mask] + (if (mask > 0) 1 else 0))
        }
    }
    println(answer)
}