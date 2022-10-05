import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val yTokenizer = StringTokenizer(jin.readLine())
        val xTokenizer = StringTokenizer(jin.readLine())
        val points = Array(n) { Pair(yTokenizer.nextToken().toLong(), xTokenizer.nextToken().toLong()) }
        points.sortBy { it.first }
        var prevY = 1L
        var prevX = 1L
        var answer = 0L
        for ((y, x) in points) {
            if (x - prevX == y - prevY) {
                if ((x + y) % 2L == 0L) {
                    answer += x - prevX
                }
            } else {
                if ((prevX + prevY) % 2L == 0L) {
                    prevY++
                }
                answer += (((y - prevY) - (x - prevX)) + 1L) / 2L
            }
            prevY = y
            prevX = x
        }
        out.appendln(answer)
    }
    print(out)
}