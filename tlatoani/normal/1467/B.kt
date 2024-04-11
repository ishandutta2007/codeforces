import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        var ay = jin.readLine().split(" ").map { it.toInt() }.toMutableList()
        ay = (listOf(ay[0]) + ay + listOf(ay.last())).toMutableList()
        if (n <= 2) {
            out.appendln(0)
        } else {
            var minChange = 0
            fun isHalley(j: Int) = ay[j] > max(ay[j - 1], ay[j + 1]) || ay[j] < min(ay[j - 1], ay[j + 1])
            fun judge(j: Int) = (if (isHalley(j - 1)) 1 else 0) + (if (isHalley(j)) 1 else 0) + (if (isHalley(j + 1)) 1 else 0)
            if (isHalley(2) || isHalley(n - 1)) {
                minChange = -1
            }
            for (j in 2 until n) {
                val orig = ay[j]
                val initial = judge(j)
                for (k in listOf(0, Int.MIN_VALUE, ay[j - 1], ay[j + 1])) {
                    ay[j] = k
                    minChange = min(minChange, judge(j) - initial)
                }
                ay[j] = orig
            }
            out.appendln((1..n).count(::isHalley) + minChange)
        }
    }
    print(out)
}