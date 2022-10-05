fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        println(if (readLine()!!.split(" ").map { it.toInt() }.sum() == m) "YES" else "NO")
    }
}