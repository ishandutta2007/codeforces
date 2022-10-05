fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var upper = 44721
        var lower = 0
        while (upper > lower) {
            val mid = (upper + lower + 1) / 2
            if (mid * mid <= (2 * n) - 1) {
                lower = mid
            } else {
                upper = mid - 1
            }
        }
        println(((upper + 1) / 2) - 1)
    }
}