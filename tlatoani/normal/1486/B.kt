fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = Array(n) { 0L }
        val ys = Array(n) { 0L }
        for (j in 0 until n) {
            val (x, y) = readLine()!!.split(" ").map { it.toLong()}
            xs[j] = x
            ys[j] = y
        }
        xs.sort()
        ys.sort()
        println((xs[n / 2] - xs[(n - 1) / 2] + 1L) * (ys[n / 2] - ys[(n - 1) / 2] + 1L))
    }
}