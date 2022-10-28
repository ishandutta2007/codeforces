import java.util.*

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    if (n >= m) {
        println(n - m)
        return
    }

    val dist = IntArray(2 * m) { -1 }
    dist[n] = 0

    val queue = LinkedList<Int>()
    queue.offer(n)

    while (!queue.isEmpty()) {
        val u = queue.pop()
        if (u > 1 && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1
            queue.offer(u - 1)
        }
        if (u < m && dist[2 * u] == -1) {
            dist[2 * u] = dist[u] + 1
            queue.offer(2 * u)
        }
    }

    println(dist[m])
}