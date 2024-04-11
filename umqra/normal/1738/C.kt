import kotlin.math.absoluteValue

val dp = Array(2) { Array(2) { Array(2) { Array(101) { IntArray(101) { -1 } } } } }
fun winner(turn: Int, alice: Int, bob: Int, even: Int, odd: Int): Int {
    if (dp[turn][alice][bob][even][odd] != -1) {
        return dp[turn][alice][bob][even][odd]
    }
    if (even == 0 && odd == 0) {
        return if (alice == 0) 0 else 1
    }
    dp[turn][alice][bob][even][odd] = 1 - turn
    if (even > 0) {
        if (winner(1 - turn, alice, bob, even - 1, odd) == turn) {
            dp[turn][alice][bob][even][odd] = turn
        }
    }
    if (odd > 0) {
        val (nextAlice, nextBob) = if (turn == 0) (1 - alice to bob) else (alice to 1 - bob)
        if (winner(1 - turn, nextAlice, nextBob, even, odd - 1) == turn) {
            dp[turn][alice][bob][even][odd] = turn
        }
    }
    return dp[turn][alice][bob][even][odd]
}

fun main(args: Array<String>) {
    val tests = readLine()!!.toInt()
    for (t in 0 until tests) {
        val n = readLine()!!.toInt()
        val seq = readLine()!!.split(" ").map { it.toInt().absoluteValue % 2 }.groupingBy { it }.eachCount()
        println(if (winner(0, 0, 0, seq.getOrDefault(0, 0), seq.getOrDefault(1, 0)) == 0) "Alice" else "Bob")
    }
}