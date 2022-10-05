fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
        println(if (k == (n * m) - 1) "yEs" else "nO")
    }
}