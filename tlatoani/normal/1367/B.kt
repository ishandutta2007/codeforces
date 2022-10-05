import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val array = jin.readLine().split(" ").map { it.toInt() }
        if (array.count { it % 2 == 1 } == n / 2) {
            println((0 until n).count { array[it] % 2 == 1 && it % 2 == 0 })
        } else {
            println(-1)
        }
    }
}