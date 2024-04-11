import java.util.*

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    if (n % 2 == 1 && k % 2 == 0) {
        println(-1)
    } else {
        var answer = 0
        fun query(indexes: Iterable<Int>) {
            println("? ${indexes.joinToString(" ")}")
            answer = answer xor readLine()!!.toInt()
        }
        val amts = IntArray(n + 1) { 1 }
        if (n % k != 0) {
            var total = n
            outer@for (m in 3..n step 2) {
                for (j in 1..n) {
                    amts[j] = m
                    total += 2
                    if (total % k == 0 && m <= total / k) {
                        break@outer
                    }
                }
            }
        }
        val pq = PriorityQueue<Int>(compareByDescending { amts[it] })
        pq.addAll(1..n)
        while (pq.isNotEmpty()) {
            val query = mutableListOf<Int>()
            repeat(k) {
                val j = pq.remove()
                amts[j]--
                query.add(j)
            }
            query(query)
            for (j in query) {
                if (amts[j] > 0) {
                    pq.add(j)
                }
            }
        }
        println("! $answer")
    }
}