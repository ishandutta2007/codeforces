import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val t = tokenizer.nextToken().toLong()
    val problems = Array(n) {
        tokenizer = StringTokenizer(jin.readLine())
        val dif = tokenizer.nextToken().toInt()
        val time = tokenizer.nextToken().toLong()
        Problem(it + 1, dif, time)
    }
    var lower = 0
    var upper = n
    while (upper > lower) {
        val mid = (lower + upper + 1) / 2
        problems.sortBy { if (it.dif < mid) Long.MAX_VALUE else it.time }
        var works = if (mid == 0) true else problems[mid - 1].dif >= mid
        if (works) {
            var sum = 0L
            for (j in 0 until mid) {
                sum += problems[j].time
            }
            works = sum <= t
        }
        if (works) {
            lower = mid
        } else {
            upper = mid - 1
        }
    }
    problems.sortBy { if (it.dif < upper) Long.MAX_VALUE else it.time }
    println(upper)
    println(upper)
    val joiner = StringJoiner(" ")
    for (j in 0 until upper) {
        joiner.add(problems[j].ix.toString())
    }
    println(joiner)
}

data class Problem(val ix: Int, val dif: Int, val time: Long)