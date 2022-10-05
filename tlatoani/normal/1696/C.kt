fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toLong() }
        val xs = readLine()!!.split(" ").map { it.toLong() }
        val k = readLine()!!.toLong()
        val ys = readLine()!!.split(" ").map { it.toLong() }
        if (reduce(xs, m) == reduce(ys, m)) {
            println("yEs")
        } else {
            println("nO")
        }
    }
}

fun reduce(xs: List<Long>, m: Long): List<Pair<Long, Long>> {
    val decompose = xs.map { x ->
        var x = x
        var amt = 1L
        while (x % m == 0L) {
            x /= m
            amt *= m
        }
        Pair(x, amt)
    }
    val res = mutableListOf<Pair<Long, Long>>()
    for ((x, amt) in decompose) {
        if (res.isNotEmpty() && res.last().first == x) {
            res[res.lastIndex] = Pair(x, res.last().second + amt)
        } else {
            res.add(Pair(x, amt))
        }
    }
    return res
}