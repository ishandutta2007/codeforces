import java.util.*
import kotlin.math.min

fun main() {
    val (x, y) = readLine()!!.split(" ").map { it.toInt() }
    val q = LinkedList<Int>()
    for (j in 1..3) {
        q.add(y)
    }
    var answer = 0
    while (q[2] != x) {
        answer++
        q.addFirst(min(x, q[0] + q[1] - 1))
    }
    println(answer)
}