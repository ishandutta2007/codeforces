import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val array = jin.readLine().split(" ").map { it.toInt() }.toIntArray()
        for (j in 0 until n) {
            array[j] = (if (j % 2 == 0) 1 else -1) * abs(array[j])
        }
        out.appendln(array.joinToString(" "))
    }
    print(out)
}