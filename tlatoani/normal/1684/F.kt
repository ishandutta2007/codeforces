import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val xs = readLine()!!.split(" ").map { it.toInt() }
        val connected = IntArray(n) { it }
        repeat(m) {
            val (l, r) = readLine()!!.split(" ").map { it.toInt() - 1 }
            connected[r] = min(connected[r], l)
        }
        for (j in n - 2 downTo 0) {
            connected[j] = min(connected[j], connected[j + 1])
        }
        val treeSets = mutableMapOf<Int, TreeSet<Int>>()
        var leftBound = n - 1
        var rightBound = 0
        val pairs = mutableListOf<Pair<Int, Int>>()
        for (j in 0 until n) {
            val treeSet = treeSets.computeIfAbsent(xs[j]) { TreeSet() }
            treeSet.add(j)
            val k = treeSet.ceiling(connected[j])!!
            if (k != j) {
                pairs.add(Pair(k, j))
                leftBound = min(leftBound, treeSet.higher(k)!!)
                rightBound = max(rightBound, treeSet.lower(j)!!)
            }
        }
        if (pairs.isEmpty()) {
            println(0)
        } else {
            pairs.sortBy { it.first }
            var answer = n
            for ((left, right) in pairs) {
                val leftEndpoint = min(leftBound, left)
                val rightEndpoint = rightBound
                answer = min(answer, rightEndpoint - leftEndpoint + 1)
                leftBound = min(leftBound, right)
                rightBound = max(rightBound, right)
            }
            answer = min(answer, rightBound - leftBound + 1)
            println(answer)
        }
    }
}