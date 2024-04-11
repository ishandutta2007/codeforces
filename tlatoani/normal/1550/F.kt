import java.util.*
import kotlin.math.max

fun main() {
    val (n, q, s, d) = readLine()!!.split(" ").map { it.toInt() }
    val rocks = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
    val treeMap = TreeMap<Int, Int>()
    for (j in 1..n) {
        if (j != s) {
            treeMap[rocks[j]] = j
        }
    }
    val dist = IntArray(n + 1) { 1000000 }
    val pq = PriorityQueue<Rock>(compareBy { it.dist })
    dist[s] = 0
    pq.add(Rock(s, 0))
    while (pq.isNotEmpty()) {
        //println(pq.peek())
        val (j, k) = pq.remove()
        if (k == dist[j]) {
            treeMap.remove(rocks[j])
            while (true) {
                val next = treeMap.floorEntry(rocks[j] - d)?.value
                if (next != null) {
                    val l = max(k, (rocks[j] - d) - rocks[next])
                    if (l < dist[next]) {
                        dist[next] = l
                        pq.add(Rock(next, l))
                    }
                    if ((rocks[j] - d) - rocks[next] > k) {
                        break
                    } else {
                        treeMap.remove(rocks[next])
                    }
                } else {
                    break
                }
            }
            while (true) {
                val next = treeMap.ceilingEntry(rocks[j] - d)?.value
                if (next != null) {
                    val l = max(k, rocks[next] - (rocks[j] - d))
                    if (l < dist[next]) {
                        dist[next] = l
                        pq.add(Rock(next, l))
                    }
                    if (rocks[next] - (rocks[j] - d) > k) {
                        break
                    } else {
                        treeMap.remove(rocks[next])
                    }
                } else {
                    break
                }
            }
            while (true) {
                val next = treeMap.floorEntry(rocks[j] + d)?.value
                if (next != null) {
                    val l = max(k, (rocks[j] + d) - rocks[next])
                    if (l < dist[next]) {
                        dist[next] = l
                        pq.add(Rock(next, l))
                    }
                    if ((rocks[j] + d) - rocks[next] > k) {
                        break
                    } else {
                        treeMap.remove(rocks[next])
                    }
                } else {
                    break
                }
            }
            while (true) {
                val next = treeMap.ceilingEntry(rocks[j] + d)?.value
                if (next != null) {
                    val l = max(k, rocks[next] - (rocks[j] + d))
                    if (l < dist[next]) {
                        dist[next] = l
                        pq.add(Rock(next, l))
                    }
                    if (rocks[next] - (rocks[j] + d) > k) {
                        break
                    } else {
                        treeMap.remove(rocks[next])
                    }
                } else {
                    break
                }
            }
            if (j != s) {
                treeMap.lowerEntry(rocks[j])?.value?.let {
                    val l = k + (rocks[j] - rocks[it])
                    if (l < dist[it]) {
                        dist[it] = l
                        pq.add(Rock(it, l))
                    }
                }
                treeMap.higherEntry(rocks[j])?.value?.let {
                    val l = k + (rocks[it] - rocks[j])
                    if (l < dist[it]) {
                        dist[it] = l
                        pq.add(Rock(it, l))
                    }
                }
            }
        }
    }
    //println(dist.contentToString())
    val out = StringBuilder()
    repeat(q) {
        val (j, k) = readLine()!!.split(" ").map { it.toInt() }
        out.appendln(if (k >= dist[j]) "Yes" else "No")
    }
    print(out)
}

data class Rock(val index: Int, val dist: Int)