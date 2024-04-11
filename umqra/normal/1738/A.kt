import java.lang.Integer.min
import java.lang.Long.max

fun alternate(a: List<Long>, b: List<Long>): Long {
    if (a.isEmpty() || b.isEmpty()) return 0
    val length = min(a.size, b.size - 1)
    return a.take(length + 1).sum() + b.take(length).sum()
}

fun main() {
    val tests = Integer.parseInt(readLine())
    for (t in 1..tests) {
        val n = Integer.parseInt(readLine())
        val type = readLine()!!.split(' ').map { it.toLong() }
        val damage = readLine()!!.split(' ').map { it.toLong() }
        val a = mutableListOf<Long>()
        val b = mutableListOf<Long>()
        for (i in 0 until n) {
            (if (type[i] == 0L) a else b).add(damage[i])
        }
        a.sortByDescending { it }
        b.sortByDescending { it }
        val best = a.sum() + b.sum() + max(alternate(a, b), alternate(b, a))
        println(best)
    }
}