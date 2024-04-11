fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    for (i in 0 until n) {
        println(when {
            i % 2 == 0 -> "#".repeat(m)
            i % 4 == 1 -> ".".repeat(m - 1) + "#"
            else -> "#" + ".".repeat(m - 1)
        });
    }
}