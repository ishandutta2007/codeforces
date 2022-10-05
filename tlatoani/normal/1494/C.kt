import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val ay = jin.readLine().split(" ").map { it.toInt() }
        val by = jin.readLine().split(" ").map { it.toInt() }
        var j = 0
        while (j < ay.size && ay[j] < 0) {
            j++
        }
        var k = 0
        while (k < by.size && by[k] < 0) {
            k++
        }
        out.appendln(solve(ay.subList(0, j).map { -it }.reversed(), by.subList(0, k).map { -it }.reversed()) + solve(ay.subList(j, n), by.subList(k, m)))
    }
    print(out)
}

fun solve(ay: List<Int>, by: List<Int>): Int {
    if (ay.isEmpty() || by.isEmpty()) {
        return 0
    }
    val treeMap = TreeMap<Int, Int>()
    for (j in by.indices) {
        treeMap[by[j]] = j + 1
    }
    val dp = IntArray(ay.size + 1)
    for (j in ay.lastIndex downTo 0) {
        dp[j] = dp[j + 1]
        if (ay[j] in treeMap) {
            dp[j]++
        }
    }
    var answer = 0
    for ((j, b) in by.withIndex()) {
        if (b >= ay[0]) {
            var upper = ay.size
            var lower = 1
            while (upper > lower) {
                val mid = (upper + lower + 1) / 2
                if (b + mid > ay[mid - 1]) {
                    lower = mid
                } else {
                    upper = mid - 1
                }
            }
            answer = max(answer, treeMap.lowerEntry(b + upper)!!.value - j + dp[upper])
        }
    }
    return answer
}