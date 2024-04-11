import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!.map { if (it == '(') 0 else 1 }
        val t = readLine()!!
        val dp = Array(n - 2) { IntArray(8) { n + 1 } }
        for (mask in 0..7) {
            dp[0][mask] = 0
            for (j in 0..2) {
                if (s[j] != (mask shr j) and 1) {
                    dp[0][mask]++
                }
            }
        }
        for (x in 1 until n - 2) {
            if (t[x - 1] == '1') {
                dp[x][6] = dp[x - 1][4] + (1 - s[x + 2])
                dp[x][5] = dp[x - 1][2] + (1 - s[x + 2])
            } else {
                for (mask in 0..15) {
                    dp[x][mask / 2] = min(dp[x][mask / 2], dp[x - 1][mask and 7] + ((mask / 8) xor s[x + 2]))
                }
            }
        }
        var answer = n + 1
        for (mask in 0..7) {
            answer = min(answer, dp[n - 3][mask])
            //println("dp_$mask = ${dp[n - 3][mask]}")
        }
        //println("dp_0_4 = ${dp[0][4]}")
        println(if (answer == n + 1) -1 else answer)
    }
}