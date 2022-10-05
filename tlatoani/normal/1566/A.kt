fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, s) = readLine()!!.split(" ").map { it.toInt() }
        println(s / ((n + 2) / 2))
    }
}