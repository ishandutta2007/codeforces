import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val freq = IntArray(3)
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            freq[tokenizer.nextToken().toInt() % 3]++
        }
        var answer = 0
        while (freq.max()!! > n / 3) {
            for (r in 0..2) {
                if (freq[r] > n / 3) {
                    answer++
                    freq[r]--
                    freq[(r + 1) % 3]++
                }
            }
        }
        println(answer)
    }
}