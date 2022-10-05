import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val xs = jin.readLine().split(" ").map { it.toLong() }
        val freq = mutableMapOf<Long, Int>()
        for (x in xs) {
            freq[x] = (freq[x] ?: 0) + 1
        }
        val sum = xs.sum()
        for (x in xs) {
            freq[x] = freq[x]!! - 1
            if ((sum - x) % 2L == 0L && freq[(sum - x) / 2L] ?: 0 != 0) {
                val answer = xs.toMutableList()
                answer.remove(x)
                answer.sort()
                answer.removeAt(answer.lastIndex)
                out.appendln(answer.joinToString(" "))
                continue@cases
            }
            freq[x] = freq[x]!! + 1
        }
        out.appendln(-1)
    }
    print(out)
}