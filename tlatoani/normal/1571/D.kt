import kotlin.math.max

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    var myWinner = 0
    var myLoser = 0
    val freqWinner = mutableMapOf<Int, Int>()
    val freqLoser = mutableMapOf<Int, Int>()
    val freqBoth = mutableMapOf<Pair<Int, Int>, Int>()
    repeat(m) {
        val (winner, loser) = readLine()!!.split(" ").map { it.toInt() }
        if (myWinner == 0) {
            myWinner = winner
            myLoser = loser
        }
        freqWinner[winner] = (freqWinner[winner] ?: 0) + 1
        freqLoser[loser] = (freqLoser[loser] ?: 0) + 1
        freqBoth[Pair(winner, loser)] = (freqBoth[Pair(winner, loser)] ?: 0) + 1
    }
    var answer = 1
    for (winner in 1..n) {
        for (loser in 1..n) {
            if (winner != loser) {
                val fw = freqWinner[winner] ?: 0
                val fl = freqLoser[loser] ?: 0
                val fb = freqBoth[Pair(winner, loser)] ?: 0
                val rank = when {
                    winner == myWinner && loser == myLoser -> 1
                    winner == myWinner || loser == myLoser -> fb + 1
                    else -> fw + fl - fb + 1
                }
                answer = max(answer, rank)
            }
        }
    }
    println(answer)
}