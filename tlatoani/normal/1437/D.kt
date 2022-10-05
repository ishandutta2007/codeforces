import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        var answer = 1
        var here = 1
        var next = 0
        var last = 0
        val tokenizer = StringTokenizer(jin.readLine())
        tokenizer.nextToken()
        for (j in 2..n) {
            val k = tokenizer.nextToken().toInt()
            if (k < last) {
                if (here == 1) {
                    answer++
                    here = next
                    next = 0
                } else {
                    here--
                }
            }
            next++
            last = k
        }
        println(answer)
    }
}