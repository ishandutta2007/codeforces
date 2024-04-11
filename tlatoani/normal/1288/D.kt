import java.util.*

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val a = Array(n) {
        tokenizer = StringTokenizer(readLine()!!)
        IntArray(m) { tokenizer.nextToken().toInt() }
    }
    var upper = 1000000000
    var lower = 0
    var answerI = -1
    var answerJ = -1
    while (upper > lower) {
        val mid = (upper + lower + 1) / 2
        val dp = IntArray(1 shl m) { -1 }
        for (j in 0 until n) {
            var mask = 0
            for (k in 0 until m) {
                if (a[j][k] >= mid) {
                    mask += 1 shl k
                }
            }
            dp[mask] = j
        }
        for (mask in (1 shl m) - 1 downTo 1) {
            if (dp[mask] != -1) {
                for (k in 0 until m) {
                    if ((mask and (1 shl k)) != 0) {
                        dp[mask - (1 shl k)] = dp[mask]
                    }
                }
            }
        }
        answerI = -1
        answerJ = -1
        for (mask in 0 until (1 shl m)) {
            answerI = dp[mask]
            answerJ = dp[(1 shl m) - 1 - mask]
            if (answerI != -1 && answerJ != -1) {
                break
            }
        }
        if (answerI != -1 && answerJ != -1) {
            lower = mid
        } else {
            upper = mid - 1
        }
    }
    val dp = IntArray(1 shl m) { -1 }
    for (j in 0 until n) {
        var mask = 0
        for (k in 0 until m) {
            if (a[j][k] >= upper) {
                mask += 1 shl k
            }
        }
        dp[mask] = j
    }
    for (mask in (1 shl m) - 1 downTo 1) {
        if (dp[mask] != -1) {
            for (k in 0 until m) {
                if ((mask and (1 shl k)) != 0) {
                    dp[mask - (1 shl k)] = dp[mask]
                }
            }
        }
    }
    answerI = -1
    answerJ = -1
    for (mask in 0 until (1 shl m)) {
        answerI = dp[mask]
        answerJ = dp[(1 shl m) - 1 - mask]
        if (answerI != -1 && answerJ != -1) {
            break
        }
    }
    println("${answerI + 1} ${answerJ + 1}")
}