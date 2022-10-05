import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val weights = jin.readLine().split(" ").map { it.toInt() }
        var answer = 0
        for (s in 2..2 * n) {
            val ll = LinkedList<Int>()
            ll.addAll(weights)
            var pos = 0
            while (ll.isNotEmpty()) {
                var w = ll.removeFirst()
                if (ll.remove(s - w)) {
                    pos++
                }
            }
            answer = max(answer, pos)
        }
        out.appendln(answer)
    }
    print(out)
}