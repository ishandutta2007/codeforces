import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        if (c > 1) {
            jin.readLine()
        }
        val line = jin.readLine().split(" ")
        var n = line[0].toLong()
        val m = line[1].toInt()
        val joy = LongArray((2 * m) + 1)
        for (j in 1..m) {
            val (a, b) = jin.readLine().split(" ").map { it.toLong() }
            joy[j] = a
            joy[j + m] = b
        }
        val types = (1..2 * m).sortedByDescending { joy[it] }
        var answer = 0L
        var curr = 0L
        val used = BooleanArray(m + 1)
        for (type in types) {
            if (type <= m) {
                n--
                curr += joy[type]
                used[type] = true
                if (n == 0L) {
                    answer = max(answer, curr)
                    break
                }
            } else {
                if (used[type - m]) {
                    answer = max(answer, curr + (n * joy[type]))
                    break
                } else {
                    answer = max(answer, curr + joy[type - m] + ((n - 1L) * joy[type]))
                }
            }
        }
        out.appendln(answer)
    }
    print(out)
}