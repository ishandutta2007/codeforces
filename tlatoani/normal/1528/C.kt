import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    repeat(jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val children = Array(2) { Array(n + 1) { mutableListOf<Int>() } }
        for (s in 0..1) {
            val tokenizer = StringTokenizer(jin.readLine())
            for (a in 2..n) {
                children[s][tokenizer.nextToken().toInt()].add(a)
            }
        }
        val l = IntArray(n + 1)
        val r = IntArray(n + 1)
        var k = 0
        fun dfs1(a: Int) {
            k++
            l[a] = k
            for (b in children[1][a]) {
                dfs1(b)
            }
            r[a] = k
        }
        dfs1(1)
        val treeMap = TreeMap<Int, Int>()
        var answer = 0
        fun dfs2(a: Int) {
            val floorEntry = treeMap.floorEntry(l[a])
            if (floorEntry != null && floorEntry.value >= r[a]) {
                treeMap.remove(floorEntry.key)
            }
            treeMap[l[a]] = r[a]
            answer = max(answer, treeMap.size)
            for (b in children[0][a]) {
                dfs2(b)
            }
            treeMap.remove(l[a])
            if (floorEntry != null && floorEntry.value >= r[a]) {
                treeMap[floorEntry.key] = floorEntry.value
            }
        }
        dfs2(1)
        out.appendln(answer)
    }
    print(out)
}