fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val answer = Array(n) { y -> IntArray(n) { x -> when {
            y == x -> 99
            (y + 1) % n == x -> 503 - (4 * (n - 2)) - 99
            else -> 4
        } } }
        answer.forEach { println(it.joinToString(" ")) }
    }
}