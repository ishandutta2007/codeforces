import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val from = LongArray(n + 1)
    val to = LongArray(n + 1)
    for (j in 1..n) {
        val (beauty, floor) = jin.readLine().split(" ").map { it.toLong() }
        from[j] = beauty + floor
        to[j] = beauty
    }
    val citiesByTo = (1..n).sortedBy { to[it] }
    val dist = LongArray(n + 1) { Long.MAX_VALUE }
    dist[citiesByTo[0]] = 0L
    val treeMap1 = TreeMap<Long, Long>()
    val treeMap2 = TreeMap<Long, Long>()
    treeMap1[from[citiesByTo[0]]] = 0L - from[citiesByTo[0]]
    treeMap2[from[citiesByTo[0]]] = 0L
    for (a in citiesByTo.subList(1, n)) {
        val entry1 = treeMap1.floorEntry(to[a])
        if (entry1 != null) {
            dist[a] = min(dist[a], entry1.value + to[a])
        }
        val entry2 = treeMap2.ceilingEntry(to[a])
        if (entry2 != null) {
            dist[a] = min(dist[a], entry2.value)
        }
        if (treeMap1.firstKey() > from[a] || treeMap1.floorEntry(from[a]).value > dist[a] - from[a]) {
            while (treeMap1.isNotEmpty() && treeMap1.lastKey() >= from[a] && treeMap1.ceilingEntry(from[a]).value >= dist[a] - from[a]) {
                treeMap1.remove(treeMap1.ceilingKey(from[a]))
            }
            treeMap1[from[a]] = dist[a] - from[a]
        }
        if (treeMap2.lastKey() < from[a] || treeMap2.ceilingEntry(from[a]).value > dist[a]) {
            while (treeMap2.isNotEmpty() && treeMap2.firstKey() <= from[a] && treeMap2.floorEntry(from[a]).value >= dist[a]) {
                treeMap2.remove(treeMap2.floorKey(from[a]))
            }
            treeMap2[from[a]] = dist[a]
        }
    }
    val answer = (from.sum() - to.sum()) + dist[citiesByTo.last()]
    println(answer)
}