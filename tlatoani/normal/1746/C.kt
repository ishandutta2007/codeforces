fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
        val answer = listOf(1) + (2..n).sortedBy { xs[it - 1] - xs[it] }
        println(answer.joinToString(" "))
    }
}