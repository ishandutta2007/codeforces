import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val s = jin.readLine()
        println(((1 until n).count { s[it - 1] == s[it] } + 1) / 2)
    }
}