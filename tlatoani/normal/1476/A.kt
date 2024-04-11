fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toLong() }
        println(((((n + k - 1L) / k) * k) + n - 1L) / n)
    }
}