import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val last = IntArray(3)
        var answer = 115115115
        var k = 0
        for (chara in jin.readLine()) {
            k++
            last[chara - '1'] = k
            if (last.min()!! > 0) {
                answer = min(answer, k - last.min()!! + 1)
            }
        }
        println(answer % 115115115)
    }
}