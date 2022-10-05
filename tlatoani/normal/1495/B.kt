import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val p = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    var prev2 = 0
    var prev = 0
    var start = 0
    var end = 0
    val runs = mutableListOf<Run>()
    for (j in 1..n) {
        val k = p[j]
        if (prev != 0) {
            if (prev2 != 0) {
                if ((k > prev) == (prev > prev2)) {
                    end = j
                } else {
                    runs.add(Run(start, end))
                    start = j - 1
                    end = j
                }
            } else {
                start = j - 1
                end = j
            }
        }
        prev2 = prev
        prev = k
    }
    runs.add(Run(start, end))
    val maxLength = runs.map { it.end - it.start }.max()!!
    var answer = 0
    if (maxLength % 2 == 0 && runs.count { it.end - it.start == maxLength } == 2) {
        val run1 = runs.first { it.end - it.start == maxLength }
        val run2 = runs.last { it.end - it.start == maxLength }
        if (run1.end == run2.start) {
            val j = run1.end
            if (p[j] > p[j - 1] && p[j] > p[j + 1]) {
                answer = 1
            }
        }
    }
    println(answer)
}

data class Run(val start: Int, val end: Int)