import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val s = " " + readLine()!!
        val left = IntArray(n + 1)
        left[0] = m
        for (j in 1..n) {
            left[j] = if (s[j] == '1') 0 else (left[j - 1] + 1)
        }
        val right = IntArray(n + 2)
        right[n + 1] = m
        for (j in n downTo 1) {
            right[j] = if (s[j] == '1') 0 else (right[j + 1] + 1)
        }
        val answer = CharArray(n + 1) { j -> if (s[j] == '1' || (min(left[j], right[j]) <= m && left[j] != right[j])) '1' else '0' }
        println(String(answer).substring(1, n + 1))
    }
}