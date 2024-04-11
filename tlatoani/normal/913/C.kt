import java.util.*
import kotlin.math.min

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    var l = tokenizer.nextToken().toLong()
    tokenizer = StringTokenizer(readLine()!!)
    val costs = LongArray(31) { if (it < n) tokenizer.nextToken().toLong() else Long.MAX_VALUE }
    for (j in 1 until 31) {
        costs[j] = min(costs[j], 2L * costs[j - 1])
    }
    fun getAnswer(v: Long): Long {
        var res = 0L
        for (j in 0 until 31) {
            if ((v shr j) and 1L != 0L) {
                res += costs[j]
            }
        }
        return res
    }
    var answer = Long.MAX_VALUE
    while (l <= 1L shl 30) {
        answer = min(answer, getAnswer(l))
        l += l and -l
    }
    println(answer)
}