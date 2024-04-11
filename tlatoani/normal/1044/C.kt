import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    var minX = Int.MAX_VALUE
    var maxX = Int.MIN_VALUE
    var minY = Int.MAX_VALUE
    var maxY = Int.MIN_VALUE
    val points = Array(n) {
        val (x, y) = jin.readLine().split(" ").map { it.toInt() }
        minX = min(minX, x)
        maxX = max(maxX, x)
        minY = min(minY, y)
        maxY = max(maxY, y)
        Point(x, y)
    }
    var answer3 = 0
    for (p in points) {
        answer3 = max(answer3, max(p.x - minX, maxX - p.x) + max(p.y - minY, maxY - p.y))
    }
    print(2 * answer3)
    println(" ${2 * (maxX - minX + maxY - minY)}".repeat(n - 3))
}

data class Point(val x: Int, val y: Int)