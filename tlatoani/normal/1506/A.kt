fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, m, x) = readLine()!!.split(" ").map { it.toLong() }
        println((m * ((x - 1) % n)) + (((x - 1) / n) + 1))
    }
}