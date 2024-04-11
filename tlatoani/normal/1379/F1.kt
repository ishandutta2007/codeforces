import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, q) = jin.readLine().split(" ").map { it.toInt() }
    val treeMap0 = TreeMap<Int, Int>()
    val treeMap1 = TreeMap<Int, Int>()
    val out = StringBuilder()
    var answer = true
    for (j in 1..q) {
        val (k1, k2) = jin.readLine().split(" ").map { it.toInt() }
        val y = (k1 + 1) / 2
        val x = (k2 + 1) / 2
        if (k1 % 2 == 0) {
            if (treeMap1.floorEntry(y)?.value ?: Int.MAX_VALUE <= x) {
                answer = false
            }
            if (treeMap0.ceilingEntry(y)?.value ?: 0 < x) {
                var entry = treeMap0.floorEntry(y)
                while (entry != null && entry.value <= x) {
                    treeMap0.remove(entry.key)
                    entry = treeMap0.floorEntry(y)
                }
                treeMap0[y] = x
            }
        } else {
            if (treeMap0.ceilingEntry(y)?.value ?: 0 >= x) {
                answer = false
            }
            if (treeMap1.floorEntry(y)?.value ?: Int.MAX_VALUE > x) {
                var entry = treeMap1.ceilingEntry(y)
                while (entry != null && entry.value >= x) {
                    treeMap1.remove(entry.key)
                    entry = treeMap1.ceilingEntry(y)
                }
                treeMap1[y] = x
            }
        }
        out.appendln(if (answer) "YES" else "NO")
    }
    print(out)
}