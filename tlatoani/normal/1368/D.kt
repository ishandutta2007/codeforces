import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val freq = IntArray(20)
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        for (e in 0..19) {
            if (((k shr e) and 1) == 1) {
                freq[e]++
            }
        }
    }
    val after = LongArray(n)
    for (e in 0..19) {
        for (j in 0 until freq[e]) {
            after[j] += 1L shl e
        }
    }
    var answer = 0L
    for (k in after) {
        answer += k * k
    }
    println(answer)
}