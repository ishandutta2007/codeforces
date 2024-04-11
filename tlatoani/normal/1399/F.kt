import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val segments = Array(n + 1) {
            if (it == n) {
                Segment(-115115115, 115115115)
            } else {
                val (l, r) = jin.readLine().split(" ").map { it.toInt() }
                Segment(l, r)
            }
        }
        segments.sortBy { it.to - it.from }
        for (r in 0..n) {
            val children = mutableListOf<Segment>()
            for (segment in segments) {
                if (segment.from >= segments[r].from && segment.to <= segments[r].to) {
                    children.add(segment)
                }
            }
            children.sortBy { it.to }
            val dp = TreeMap<Int, Int>()
            dp[segments[r].from - 1] = 0
            for (child in children) {
                val pos = dp.lowerEntry(child.from).value + child.dp
                if (pos > dp.lastEntry().value) {
                    dp[child.to] = pos
                }
            }
            segments[r].dp = dp.lastEntry().value + 1
        }
        out.appendln(segments.last().dp - 1)
    }
    print(out)
}

class Segment(val from: Int, val to: Int) {
    var dp = 0
}