import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val matrix = Array(n) {
        tokenizer = StringTokenizer(jin.readLine())
        IntArray(m) {
            val res = tokenizer.nextToken().toInt() - 1
            if (res >= 0 && res < n * m) res else -1
        }
    }
    var answer = 0
    for (x in 0 until m) {
        val changes = IntArray(n) { n + it }
        for (y in 0 until n) {
            if (matrix[y][x] != -1 && matrix[y][x] % m == x) {
                changes[(y - (matrix[y][x] / m) + n) % n]--
            }
        }
        answer += changes.min()!!
    }
    println(answer)
}