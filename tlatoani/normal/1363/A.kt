import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, x) = jin.readLine().split(" ").map { it.toInt() }
        val array = jin.readLine().split(" ").map { it.toInt() }
        if ((x < n && array.any { it % 2 == 0} && array.any { it % 2 == 1}) || array.subList(0, x).sum() % 2 == 1) {
            println("yEs")
        } else {
            println("nO")
        }
    }
}