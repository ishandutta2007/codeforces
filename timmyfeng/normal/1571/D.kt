import kotlin.math.*

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val tallyFirst = IntArray(n)
    val tallyLast = IntArray(n)
    val tallyBoth = Array(n) { IntArray(n) }

    var first1 = -1
    var last1 = -1

    repeat(m) {
        val (first, last) = readLine()!!.split(" ").map { it.toInt() - 1 }
        tallyFirst[first]++
        tallyLast[last]++
        tallyBoth[first][last]++

        if (it == 0) {
            first1 = first
            last1 = last
        }
    }

    var ans = 0
    for (first in 0 until n) {
        for (last in 0 until n) {
            if (first != last && first != first1 && last != last1) {
                ans = max(ans, tallyFirst[first] + tallyLast[last] - tallyBoth[first][last])
            }
        }
    }

    println(ans + 1)
}