import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val things = jin.readLine().split(" ").map { it.toInt() }.toIntArray()
        for (j in 0 until n) {
            things[j] = (((things[j] + j) % n) + n) % n
        }
        out.appendln(if (things.toSet().size == n) "yEs" else "nO")
    }
    print(out)
}