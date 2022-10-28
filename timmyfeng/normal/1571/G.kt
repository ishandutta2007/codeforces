import kotlin.math.*

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val attacks = Array(n) { mutableListOf<Pair<Int, Int>>() }

    for (i in 0 until n) {
        val k = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
        val b = readLine()!!.split(" ").map { it.toInt() }

        for (j in 0 until k) {
            if (i + b[j] >= m) {
                attacks[i + b[j] - m].add(a[j] to b[j])
            }
        }
    }

    val segtree = LongArray(2 * (m + 1))

    fun update(a: Int, x: Long) {
        var i = a + m + 1
        while (i > 0) {
            segtree[i] = max(segtree[i], x)
            i /= 2
        }
        return
    }

    fun query(a: Int, b: Int): Long {
        var i = a + m + 1
        var j = b + m + 1
        var res = 0L
        
        while (i <= j) {
            if (i % 2 == 1) res = max(res, segtree[i++])
            if (j % 2 == 0) res = max(res, segtree[j--])
            i /= 2
            j /= 2
        }
        
        return res
    }

    for (row in attacks) {
        row.sortBy { it.second }
        for ((damage, barricades) in row) {
            update(barricades, query(barricades, m) + damage)
        }
    }

    println(query(0, m))
}