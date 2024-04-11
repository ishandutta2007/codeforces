import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val points = Array(n) { Pair(it.toLong(), tokenizer.nextToken().toLong()) }
    for (j in 0..1) {
        for (k in j + 1..2) {
            val a = points[j]
            val b = points[k]
            val onLine = mutableListOf<Pair<Long, Long>>()
            val notOnLine = mutableListOf<Pair<Long, Long>>()
            for (c in points) {
                if (collinear(a, b, c)) {
                    onLine.add(c)
                } else {
                    notOnLine.add(c)
                }
            }
            if (notOnLine.isNotEmpty()) {
                if (notOnLine.size == 1) {
                    println("yEs")
                    return
                } else {
                    val d = notOnLine[0]
                    val e = notOnLine[1]
                    if (((b.first - a.first) * (e.second - d.second)) == ((e.first - d.first) * (b.second - a.second)) && notOnLine.all { f -> collinear(d, e, f) } && !onLine.any { c -> collinear(d, e, c) }) {
                        println("yEs")
                        return
                    }
                }
            }
        }
    }
    println("nO")
}

fun collinear(a: Pair<Long, Long>, b: Pair<Long, Long>, c: Pair<Long, Long>) = ((b.first - a.first) * (c.second - a.second)) == ((c.first - a.first) * (b.second - a.second))