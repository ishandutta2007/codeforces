import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    cases@for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val hs = jin.readLine().split(" ").map { it.toLong() }.toLongArray()
        for (j in 0 until n - 1) {
            if (hs[j] < j.toLong()) {
                println("nO")
                continue@cases
            }
            hs[j + 1] += hs[j] - j.toLong()
            hs[j] = j.toLong()
        }
        println(if (n == 1 || hs.last() > hs[n - 2]) "Yes" else "No")
    }
}