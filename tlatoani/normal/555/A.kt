import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = jin.readLine().split(" ").map { it.toInt() }
    var answer = 0
    for (j in 1..k) {
        val tokenizer = StringTokenizer(jin.readLine())
        var prev = 0
        for (j2 in 1..tokenizer.nextToken().toInt()) {
            val m = tokenizer.nextToken().toInt()
            if (prev + 1 == m) {
                prev++
            } else if (prev == 0) {
                prev = -1
            } else {
                answer++
            }
        }
        if (prev != -1) {
            answer += n - prev
        }
    }
    println(answer)
}