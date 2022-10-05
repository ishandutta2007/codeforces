fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, ks) = readLine()!!.split(" ").map { it.toInt() }
        val k = ks.toLong()
        val p = readLine()!!.split(" ").map { it.toLong() }.toLongArray()
        for (j in 1 until n) {
            p[j] += p[j - 1]
        }
        var upper = 1000000000000000L
        var lower = 0L
        while (upper > lower) {
            val mid = (upper + lower) / 2L
            if ((1 until n).any { j -> (p[j] - p[j - 1]) * 100L > (p[j - 1] + mid) * k }) {
                lower = mid + 1L
            } else {
                upper = mid
            }
        }
        println(upper)
    }
}