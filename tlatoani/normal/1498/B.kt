import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, wb) = jin.readLine().split(" ").map { it.toInt() }
        val ws = jin.readLine().split(" ").map { it.toInt() }.sortedDescending()
        val disp = Array(20) { LinkedList<Int>() }
        var answer = 0
        weightLoop@for (w in ws) {
            for (j in 0..19) {
                if (1 shl j >= w && disp[j].isNotEmpty()) {
                    val k = disp[j].remove() - w
                    for (j2 in 19 downTo 0) {
                        if (k >= 1 shl j2) {
                            disp[j2].add(k)
                            break
                        }
                    }
                    continue@weightLoop
                }
            }
            answer++
            val k = wb - w
            for (j2 in 19 downTo 0) {
                if (k >= 1 shl j2) {
                    disp[j2].add(k)
                    break
                }
            }
        }
        println(answer)
    }
}