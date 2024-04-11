import kotlin.math.min

fun main() {
    val dp = Array(2) { Array(2) { Array(1001) { IntArray(1001) { 1000 } } } }
    dp[0][0][0][0] = 0
    dp[1][0][0][0] = 0
    for (y in 0..1000) {
        for (x in 0..1000) {
            for (z in 0..1) {
                for (a in 0..1) {
                    if (x > 0) {
                        dp[a][z][x][y] = min(dp[a][z][x][y], 1 - dp[1][z][x - 1][y])
                    }
                    if (y > 0 && x < 1000) {
                        dp[a][z][x][y] = min(dp[a][z][x][y], 1 - dp[1][z][x + 1][y - 1])
                    }
                    if (z > 0) {
                        dp[a][z][x][y] = min(dp[a][z][x][y], 1 - dp[1][z - 1][x][y])
                    }
                    if (a == 1 && x > 0) {
                        dp[a][z][x][y] = min(dp[a][z][x][y], -dp[0][z][x][y])
                    }
                }
            }
        }
    }
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        var single = 0
        var double = 0
        for (j in 0 until n / 2) {
            if (s[j] == '0' && s[n - 1 - j] == '0') {
                double++
            } else if (s[j] == '0' || s[n - 1 - j] == '0') {
                single++
            }
        }
        val middle = if (n % 2 == 1 && s[n / 2] == '0') 1 else 0
        println(when {
            dp[1][middle][single][double] < 0 -> "ALICE"
            dp[1][middle][single][double] > 0 -> "BOB"
            else -> "DRAW"
        })
    }
}