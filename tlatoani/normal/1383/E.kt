import java.util.*

const val MOD = 1000000007L

fun main() {
    val s = readLine()!!
    if (s.all { it == '0' }) {
        println(s.length)
    } else {
        val stack = ArrayDeque<Pair<Int, Long>>()
        stack.push(Pair(0, 1L))
        var currBlock = 0
        for (k in s.indexOf('1') + 1 until s.length) {
            if (s[k] == '0') {
                currBlock++
            } else {
                var higher = 0L
                var here = 0L
                while (stack.isNotEmpty() && stack.peek().first <= currBlock) {
                    val (j, x) = stack.pop()
                    higher += x
                    higher %= MOD
                    here += (currBlock - j + 1).toLong() * x
                    here %= MOD
                }
                stack.push(Pair(currBlock + 1, higher))
                stack.push(Pair(0, here))
                currBlock = 0
            }
        }
        val answer = ((stack.map { it.second }.sum() % MOD) * (((s.indexOf('1') + 1).toLong() * (s.length - s.lastIndexOf('1')).toLong()) % MOD)) % MOD
        println(answer)
    }
}