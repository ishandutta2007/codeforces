import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    cases@for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val p = jin.readLine().split(" ").map { it.toInt() }
        for (j in 1..n - 2) {
            if (p[j - 1] < p[j] && p[j] > p[j + 1]) {
                println("YES")
                println("$j ${j + 1} ${j + 2}")
                continue@cases
            }
        }
        println("NO")
    }
}