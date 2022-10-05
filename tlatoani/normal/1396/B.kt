import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val stones = jin.readLine().split(" ").map { it.toInt() }.sortedDescending()
        val s = stones.sum()
        if (stones[0] > s - stones[0]) {
            out.appendln("T")
        } else {
            out.appendln(if (s % 2 == 1) "T" else "HL")
        }
    }
    print(out)
}