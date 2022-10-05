import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        var one = 0
        var curr = 0
        for (chara in jin.readLine()) {
            when (chara) {
                '(' -> curr++
                ')' -> curr--
            }
            if (curr == 0) {
                one++
            }
        }
        println(min(n / 2, k + one))
    }
}