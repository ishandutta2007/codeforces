import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toLong()
        val k = line[1].toLong()
        for (f in 2L..n) {
            if (n % f == 0L) {
                if (f == 2L) {
                    println(n + (2L * k))
                } else {
                    println(n + f + (2L * (k - 1L)))
                }
                break
            }
        }
    }
}