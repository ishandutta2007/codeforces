fun main() {
    val t = readLine()!!.toInt()
    for (i in 0 until t) {
        val (n, m, x) = readLine()!!.split(" ").map { it.toLong() }
        println((x - 1) % n * m + (x - 1) / n + 1)
    }
}