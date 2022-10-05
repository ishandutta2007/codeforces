import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        println(if (min(s.count { it == '0' }, s.count { it == '1' }) % 2 == 1) "dA" else "nEt")
    }
}