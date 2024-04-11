import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k, x) = jin.readLine().split(" ").map { it.toInt() }
    val images = jin.readLine().split(" ").map { it.toLong() }
    var upper = images.sum()
    var lower = 0L
    val pq = PriorityQueue<Long>(reverseOrder())
    while (upper > lower) {
        val mid = (upper + lower) / 2L
        var removed = 0
        var ix = 0
        var curr = 0L
        for (image in images) {
            ix++
            curr += image
            pq.add(image)
            if (curr > mid) {
                curr -= pq.remove()
                ix--
                removed++
            }
            if (ix == x) {
                ix = 0
                curr = 0L
                pq.clear()
            }
        }
        if (removed <= k) {
            upper = mid
        } else {
            lower = mid + 1L
        }
        pq.clear()
    }
    println(upper)
}