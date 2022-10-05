import kotlin.math.abs
import kotlin.math.min

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        var answer = 0
        for (from in 0 until n) {
            for (to in from + 1..min(n, from + 4)) {
                var good = true
                for (j in from until to) {
                    for (k in from until to) {
                        for (l in from until to) {
                            if (j != k && k != l && j != l && abs(l - j) + abs(ay[l] - ay[j]) == abs(k - j) + abs(ay[k] - ay[j]) + abs(l - k) + abs(ay[l] - ay[k])) {
                                good = false
                            }
                        }
                    }
                }
                if (good) {
                    answer++
                }
            }
        }
        out.appendln(answer)
    }
    print(out)
}