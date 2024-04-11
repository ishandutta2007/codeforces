import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var (x, y, n) = jin.readLine().split(" ").map { it.toLong() }
        n -= y
        n -= n % x
        n += y
        println(n)
    }
}