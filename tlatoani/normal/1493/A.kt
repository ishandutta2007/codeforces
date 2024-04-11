fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val answer = (1..n).filter { it != k && 2 * it >= k }
        println(answer.size)
        println(answer.joinToString(" "))
    }
}