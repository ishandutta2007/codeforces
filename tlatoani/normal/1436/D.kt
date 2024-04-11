import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val parent = listOf(0, 0) + readLine()!!.split(" ").map { it.toInt() }
    val subtreeLeaves = LongArray(n + 1) { 1L }
    for (j in 1..n) {
        subtreeLeaves[parent[j]] = 0L
    }
    val subtreePeople = (listOf(0L) + readLine()!!.split(" ").map { it.toLong() }).toLongArray()
    var answer = 0L
    for (j in n downTo 1) {
        answer = max(answer, (subtreePeople[j] + subtreeLeaves[j] - 1L) / subtreeLeaves[j])
        subtreeLeaves[parent[j]] += subtreeLeaves[j]
        subtreePeople[parent[j]] += subtreePeople[j]
    }
    println(answer)
}