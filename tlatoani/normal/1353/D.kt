import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val answer = IntArray(n)
        val pq = PriorityQueue<Interval>(compareBy({ it.l - it.r }, { it.l }))
        pq.add(Interval(0, n - 1))
        var k = 0
        while (pq.isNotEmpty()) {
            val interval = pq.remove()
            if (interval.l <= interval.r) {
                k++
                val mid = (interval.l + interval.r) / 2
                answer[mid] = k
                pq.add(Interval(interval.l, mid - 1))
                pq.add(Interval(mid + 1, interval.r))
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}

data class Interval(val l: Int, val r: Int)