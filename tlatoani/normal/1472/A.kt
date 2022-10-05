fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var (w, h, n) = readLine()!!.split(" ").map { it.toLong() }
        var amt = 1L
        while (w % 2L == 0L) {
            w /= 2L
            amt *= 2L
        }
        while (h % 2L == 0L) {
            h /= 2L
            amt *= 2L
        }
        println(if (n <= amt) "yEs" else "nO")
    }
}