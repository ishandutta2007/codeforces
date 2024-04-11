import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().substringBefore(' ').toInt()
    val cokes = jin.readLine().split(" ").map { it.toInt() - n }.toSet()
    if (0 in cokes) {
        println(1)
    } else if (cokes.all { it > 0 } || cokes.all { it < 0 }) {
        println(-1)
    } else {
        val positive = cokes.filter { it > 0 }.toIntArray()
        val negative = cokes.filter { it < 0 }.map { -it }.toIntArray()
        var answer = 115115115
        val limit = 1000000
        val dpPositive = IntArray(limit + 1) { 115115115 }
        val dpNegative = IntArray(limit + 1) { 115115115 }
        dpPositive[0] = 0
        dpNegative[0] = 0
        for (a in positive) {
            for (j in a..limit) {
                dpPositive[j] = min(dpPositive[j], dpPositive[j - a] + 1)
            }
        }
        for (b in negative) {
            for (j in b..limit) {
                dpNegative[j] = min(dpNegative[j], dpNegative[j - b] + 1)
            }
        }
        for (j in 1..limit) {
            answer = min(answer, dpNegative[j] + dpPositive[j])
        }
        println(answer)
    }
}