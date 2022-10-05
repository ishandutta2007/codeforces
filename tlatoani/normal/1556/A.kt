fun main() {
    repeat(readLine()!!.toInt()) {
        val (c, d) = readLine()!!.split(" ").map { it.toInt() }
        println(when {
            c == d -> when (c) {
                0 -> 0
                else -> 1
            }
            c % 2 == d % 2 -> 2
            else -> -1
        })
    }
}