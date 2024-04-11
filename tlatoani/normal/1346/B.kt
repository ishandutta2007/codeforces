import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ").map { it.toInt() }
        val k1 = line[1]
        val k2 = line[2]
        var answer = 0
        var prevALot = false
        for (chara in jin.readLine()) {
            if (chara == '0') {
                prevALot = false
            } else if (prevALot && 2 * k1 >= k2) {
                prevALot = false
                answer += k2 - k1
            } else {
                prevALot = true
                answer += k1
            }
        }
        println(answer)
    }
}