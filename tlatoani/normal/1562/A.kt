fun main() {
    repeat(readLine()!!.toInt()) {
        val (l, r) = readLine()!!.split(" ").map { it.toInt() }
        println(if (r < 2 * l) r % l else ((r + 1) / 2) - 1)
    }
}