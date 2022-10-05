fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, s) = readLine()!!.split(" ").map { it.toLong() }
        var upper = s
        var lower = 0L
        while (upper > lower) {
            val mid = (upper + lower + 1L) / 2L
            var total = 0L
            var curr = mid
            var j = n
            while (j > 0L && curr > 1L) {
                total += curr
                curr = (curr + 1L) / 2L
                j--
            }
            total += j
            if (total <= s) {
                lower = mid
            } else {
                upper = mid - 1L
            }
        }
        println(upper)
    }
}