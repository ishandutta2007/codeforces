import java.util.*

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    fun query(j: Int): Int {
        println("? ${j + 1}")
        return readLine()!!.toInt()
    }
    if (n <= 650) {
        for (j in 1..350) {
            query(0)
        }
        val circle = IntArray(n) { query(it) }
        for (j in 0 until n) {
            if (circle[j] == k && circle[(j + n - 1) % n] < circle[j] && circle[(j + 1) % n] > circle[j]) {
                println("! ${j + 1}")
                return
            }
        }
    } else {
        for (j in 1..320) {
            query(0)
        }
        var best = 0
        var lowest = query(0)
        for (j in 300 until n step 300) {
            val m = query(j)
            if (m <= lowest) {
                best = j
                lowest = m
            }
        }
        val ll = LinkedList<Int>()
        for (j in best until best + n) {
            ll.addFirst(query(j % n))
            if (ll.size >= 3 && ll[2] < ll[1] && ll[1] < ll[0]) {
                println("! ${((j - 1 + n) % n) + 1}")
                return
            }
        }
    }
}