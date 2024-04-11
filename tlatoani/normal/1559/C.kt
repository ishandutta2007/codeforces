fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = listOf(0) + readLine()!!.split(" ").map { it.toInt() } + listOf(1)
        val k = (0..n).indexOfFirst { ay[it] == 0 && ay[it + 1] == 1 }
        val answer = (1..k) + listOf(n + 1) + (k + 1..n)
        println(answer.joinToString(" "))
    }
}