import java.util.*
import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val ay = listOf(0) + readLine()!!.split(" ").map { it.toInt() }.sorted()
    val prefixes = IntArray(n + 1)
    val suffixes = IntArray(n + 2)
    val bs = listOf(0) + readLine()!!.split(" ").map { it.toInt() }.sorted()
    val treeMap = TreeMap<Int, Int>()
    for (k in 1..n) {
        treeMap[ay[k]] = k
        prefixes[k] = bs[k] - ay[k]
        suffixes[k] = bs[k + 1] - ay[k]
    }
    prefixes[0] = Int.MIN_VALUE
    for (k in 1..n) {
        prefixes[k] = max(prefixes[k], prefixes[k - 1])
    }
    suffixes[n + 1] = Int.MIN_VALUE
    for (k in n downTo 1) {
        suffixes[k] = max(suffixes[k], suffixes[k + 1])
    }
    val joiner = StringJoiner(" ")
    val m = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    repeat(m) {
        val c = tokenizer.nextToken().toInt()
        val k = treeMap.lowerEntry(c)?.value ?: 0
        joiner.add(maxOf(prefixes[k], bs[k + 1] - c, suffixes[k + 1]).toString())
    }
    print(joiner)
}