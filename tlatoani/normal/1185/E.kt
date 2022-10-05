import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

const val EMPTY = '.' - 'a'

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        val n = line.substring(0, six).toInt()
        val m = line.substring(six + 1).toInt()
        val grid = Array(n) {
            jin.readLine().map { it - 'a' }
        }
        val minY = IntArray(26) { n }
        val minX = IntArray(26) { m }
        val maxY = IntArray(26) { -1 }
        val maxX = IntArray(26) { -1 }
        for (y in 0 until n) {
            for (x in 0 until m) {
                val color = grid[y][x]
                if (color != EMPTY) {
                    minY[color] = min(minY[color], y)
                    minX[color] = min(minX[color], x)
                    maxY[color] = max(maxY[color], y)
                    maxX[color] = max(maxX[color], x)
                }
            }
        }
        var works = true
        for (color in 25 downTo 0) {
            if (maxY[color] == -1) {
                continue
            }
            if (minY[color] != maxY[color] && minX[color] != maxX[color]) {
                works = false
                break
            }
            for (y in minY[color]..maxY[color]) {
                for (x in minX[color]..maxX[color]) {
                    if (grid[y][x] == EMPTY || grid[y][x] < color) {
                        works = false
                        break
                    }
                }
                if (!works) {
                    break
                }
            }
        }
        if (works) {
            out.appendln("YES")
            for (color in 24 downTo 0) {
                if (maxY[color] == -1) {
                    minY[color] = minY[color + 1]
                    minX[color] = minX[color + 1]
                    maxY[color] = maxY[color + 1]
                    maxX[color] = maxX[color + 1]
                }
            }
            if ((0..25).all { maxY[it] == -1 }) {
                out.appendln(0)
            } else {
                val k = (0..25).last { maxY[it] != -1 } + 1
                out.appendln(k)
                for (color in 0 until k) {
                    out.append(minY[color] + 1).append(' ').append(minX[color] + 1).append(' ').append(maxY[color] + 1).append(' ').appendln(maxX[color] + 1)
                }
            }
        } else {
            out.appendln("NO")
        }
    }
    print(out)
}