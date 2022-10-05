import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val divisors = Array(n + 1) { mutableListOf<Int>() }
    for (d in 1..n) {
        for (k in d + d..n step d) {
            divisors[k].add(d)
        }
    }
    val above = IntArray(n + 1) { if (it == 0) 0 else ((n / it) - 1) }
    fun eval(k: Int) = divisors[k].size - ((n / k) - 1)
    val pq = PriorityQueue<Int>(compareByDescending(::eval))
    pq.addAll((1..n).filter { above[it] == 0 })
    val answer = IntArray(n + 1)
    for (j in 1..n) {
        val k = pq.remove()
        answer[j] = answer[j - 1] + eval(k)
        for (d in divisors[k]) {
            above[d]--
            if (above[d] == 0) {
                pq.add(d)
            }
        }
    }
    println(answer.joinToString(" ").substring(2))
}