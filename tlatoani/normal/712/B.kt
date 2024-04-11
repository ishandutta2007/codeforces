import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val s = jin.readLine()
    if (s.length % 2 == 1) {
        println(-1)
    } else {
        val dy = s.sumBy { when (it) {
            'U' -> 1
            'D' -> -1
            else -> 0
        } }
        val dx = s.sumBy { when (it) {
            'R' -> 1
            'L' -> -1
            else -> 0
        } }
        println((abs(dy) + abs(dx)) / 2)
    }
}