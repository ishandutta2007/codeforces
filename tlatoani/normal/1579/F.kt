import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, d) = readLine()!!.split(" ").map { it.toInt() }
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val dist = IntArray(n) { -ay[it] }
        val q = ArrayDeque<Int>()
        q.addAll((0 until n).filter { ay[it] == 0 })
        while (q.isNotEmpty()) {
            val a = q.remove()
            val b = (a + d) % n
            if (dist[b] == -1) {
                dist[b] = dist[a] + 1
                q.add(b)
            }
        }
        if (-1 in dist) {
            println(-1)
        } else {
            println(dist.max()!!)
        }
    }
}