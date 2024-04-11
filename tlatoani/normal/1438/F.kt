import kotlin.random.Random
import kotlin.random.nextInt

fun main() {
    val h = readLine()!!.toInt()
    val n = (1 shl h) - 1
    fun query(a: Int, b: Int, c: Int): Int {
        println("? $a $b $c")
        return readLine()!!.toInt()
    }
    val random = Random(System.currentTimeMillis())
    val freq = IntArray(n + 1)
    var j = 0
    while (j < 420) {
        val q = Array(3) { random.nextInt(1..n) }.toSet().toList()
        if (q.size == 3) {
            freq[query(q[0], q[1], q[2])]++
            j++
        }
    }
    val nodes = (1..n).sortedByDescending { freq[it] }
    for (r in 1..n) {
        if (r != nodes[0] && r != nodes[1] && query(nodes[0], r, nodes[1]) == r) {
            println("! $r")
            return
        }
    }
}