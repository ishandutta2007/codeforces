import java.util.*

fun main() {
    fun split(n: Long, k: Long): Long {
        val r = n % k
        val x = n / k
        return ((k - r) * x * x) + (r * (x + 1L) * (x + 1L))
    }
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val pq = PriorityQueue<Split>(compareBy { it.delta })
    var answer = 0L
    val tokenizer = StringTokenizer(readLine()!!)
    for (j in 1..n) {
        val x = tokenizer.nextToken().toLong()
        answer += x * x
        if (x > 1L) {
            pq.add(Split(x, 2L, split(x, 2L) - split(x, 1L)))
        }
    }
    for (j in 1..k - n) {
        val s = pq.remove()
        answer += s.delta
        if (s.length > s.amt) {
            pq.add(Split(s.length, s.amt + 1L, split(s.length, s.amt + 1L) - split(s.length, s.amt)))
        }
    }
    println(answer)
}

data class Split(val length: Long, val amt: Long, val delta: Long)