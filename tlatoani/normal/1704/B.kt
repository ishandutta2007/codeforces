fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, x) = readLine()!!.split(" ").map { it.toInt() }
        val piles = readLine()!!.split(" ").map { it.toInt() }
        var answer = 0
        var min = piles[0]
        var max = piles[0]
        for (pile in piles) {
            min = kotlin.math.min(min, pile)
            max = kotlin.math.max(max, pile)
            if (max - min > 2 * x) {
                answer++
                min = pile
                max = pile
            }
        }
        println(answer)
    }
}