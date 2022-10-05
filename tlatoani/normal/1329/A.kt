import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toLong()
    val m = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(jin.readLine())
    val ls = LongArray(m) { tokenizer.nextToken().toLong() }
    if (ls.sum() < n) {
        println("-1")
        return
    }
    val answer = LongArray(m) { it.toLong() + 1 }
    if ((0 until m).any { answer[it] + ls[it] - 1 > n }) {
        println("-1")
        return
    }
    if (answer[m - 1] + ls[m - 1] - 1L < n) {
        answer[m - 1] = n - ls[m - 1] + 1L
    }
    for (j in m - 2 downTo 0) {
        if (answer[j] + ls[j] < answer[j + 1]) {
            answer[j] = answer[j + 1] - ls[j]
        }
    }
    println(answer.joinToString(" "))
}