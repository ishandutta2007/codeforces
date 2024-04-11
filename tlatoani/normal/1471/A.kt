fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, x) = readLine()!!.split(" ").map { it.toLong() }
        var answerMin = 0L
        var answerMax = 0L
        for (a in readLine()!!.split(" ").map { it.toLong() }) {
            answerMin += a
            answerMax += (a + x - 1L) / x
        }
        answerMin = (answerMin + x - 1L) / x
        println("$answerMin $answerMax")
    }
}