import java.util.*
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val prefixes = IntArray(n + 1) { 2000000000 }
        val suffixes = IntArray(n + 2) { 2000000000 }
        val tokenizer1 = StringTokenizer(readLine()!!)
        val tokenizer2 = StringTokenizer(readLine()!!)
        repeat(k) {
            val x = tokenizer1.nextToken().toInt()
            val t = tokenizer2.nextToken().toInt()
            prefixes[x] = t
            suffixes[x] = t
        }
        for (j in 1..n) {
            prefixes[j] = min(prefixes[j - 1] + 1, prefixes[j])
        }
        for (j in n downTo 1) {
            suffixes[j] = min(suffixes[j + 1] + 1, suffixes[j])
        }
        val answer = prefixes.zip(suffixes).map { (t, u) -> min(t, u) }
        println(answer.subList(1, n + 1).joinToString(" "))
    }
}