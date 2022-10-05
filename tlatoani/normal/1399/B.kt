import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toLong() }
        val by = jin.readLine().split(" ").map { it.toLong() }
        val am = ay.min()!!
        val bm = by.min()!!
        var answer = 0L
        for (j in 0 until n) {
            answer += max(ay[j] - am, by[j] - bm)
        }
        out.appendln(answer)
    }
    print(out)
}