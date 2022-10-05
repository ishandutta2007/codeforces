import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MOD = 1000000007L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val tokenizer = StringTokenizer(jin.readLine())
        val map = mutableMapOf<Long, Long>()
        map[0L] = 1L
        var sum = 0L
        var amt = 1L
        for (j in 1..n) {
            val prevAMT = amt
            amt *= 2L
            amt -= map[sum] ?: 0L
            amt %= MOD
            map[sum] = prevAMT
            sum += tokenizer.nextToken().toLong()
        }
        amt += MOD
        amt %= MOD
        out.appendln(amt)
    }
    print(out)
}