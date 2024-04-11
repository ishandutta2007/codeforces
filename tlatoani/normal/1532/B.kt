fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b, k) = readLine()!!.split(" ").map { it.toLong() }
        if (k % 2L == 0L) {
            println((k / 2L) * (a - b))
        } else {
            println(((k / 2L) * (a - b)) + a)
        }
    }
}