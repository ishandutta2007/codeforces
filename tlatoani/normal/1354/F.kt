import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val k = line[1].toInt()
        val minions = Array(n) {
            val line = jin.readLine().split(" ")
            Minion(it + 1, line[0].toInt(), line[1].toLong())
        }
        minions.sortBy { it.b }
        var optimal = -1L
        val answer = mutableListOf<Int>()
        for (r in 0 until n) {
            val dp = Array(n + 1) { LongArray(k) { -1L } }
            val used = Array(n + 1) { BooleanArray(k) }
            dp[0][0] = 0L
            for (j in 0 until n) {
                for (lambda in 0 until k) {
                    if (dp[j][lambda] >= 0L) {
                        dp[j + 1][lambda] = dp[j][lambda] + ((k - 1).toLong() * minions[j].b)
                    }
                    if (j != r && lambda > 0 && dp[j][lambda - 1] >= 0L && dp[j][lambda - 1] + ((lambda - 1).toLong() * minions[j].b) + minions[j].a > dp[j + 1][lambda]) {
                        dp[j + 1][lambda] = dp[j][lambda - 1] + ((lambda - 1).toLong() * minions[j].b) + minions[j].a
                        used[j + 1][lambda] = true
                    }
                }
            }
            if (dp[n][k - 1] + minions[r].a > optimal) {
                optimal = dp[n][k - 1] + minions[r].a
                answer.clear()
                answer.add(minions[r].ix)
                var lambda = k - 1
                for (j in n downTo 1) {
                    if (used[j][lambda]) {
                        lambda--
                    } else if (j != r + 1) {
                        answer.add(-minions[j - 1].ix)
                        answer.add(minions[j - 1].ix)
                    }
                }
                lambda = k - 1
                for (j in n downTo 1){
                    if (used[j][lambda]) {
                        answer.add(minions[j - 1].ix)
                        lambda--
                    }
                }
            }
        }
        //println("optimal = $optimal")
        println(answer.size)
        println(answer.reversed().joinToString(" "))
    }
}

data class Minion(val ix: Int, val a: Int, val b: Long)