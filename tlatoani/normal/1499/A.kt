fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k1, k2) = readLine()!!.split(" ").map { it.toInt() }
        val (w, b) = readLine()!!.split(" ").map { it.toInt() }
        println(if (2 * w <= k1 + k2 && 2 * b <= (2 * n) - k1 - k2) "yEs" else "nO")
    }
}