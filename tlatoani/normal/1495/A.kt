import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.sqrt

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val miners = mutableListOf<Long>()
        val diamondMines = mutableListOf<Long>()
        for (j in 1..2 * n) {
            val (x, y) = jin.readLine().split(" ").map { abs(it.toLong()) }
            if (x == 0L) {
                miners.add(y)
            } else {
                diamondMines.add(x)
            }
        }
        miners.sort()
        diamondMines.sort()
        val answer = (0 until n).map { sqrt(((miners[it] * miners[it]) + (diamondMines[it] * diamondMines[it])).toDouble()) }.sum()
        out.appendln(answer)
    }
    print(out)
}