import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var d = 0
        var answer = 0
        jin.readLine()
        for (chara in jin.readLine()) {
            when (chara) {
                '(' -> d++
                ')' -> d--
            }
            answer = max(answer, -d)
        }
        println(answer)
    }
}