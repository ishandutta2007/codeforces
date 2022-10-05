import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val matrix = Array(n) { jin.readLine().map { 1 shl (it - 'A') } }
    val above = Array(n + 1) { IntArray(m + 1) }
    val stack = ArrayDeque<Int>()
    val amts = LongArray(32)
    for (mask in 0 until 32) {
        for (y in 1..n) {
            var curr = 0
            stack.push(0)
            for (x in 1..m) {
                if (matrix[y - 1][x - 1] and mask == 0) {
                    above[y][x] = 0
                } else {
                    above[y][x] = above[y - 1][x] + 1
                }
                while (above[y][x] < above[y][stack.peek()]) {
                    val x2 = stack.pop()
                    curr -= (x2 - stack.peek()) * above[y][x2]
                }
                curr += (x - stack.peek()) * above[y][x]
                amts[mask] += curr.toLong()
                stack.push(x)
            }
            stack.clear()
        }
    }
    val answers = LongArray(6)
    for (mask in 0 until 32) {
        for (submask in 0 until mask) {
            if (submask and mask == submask) {
                amts[mask] -= amts[submask]
            }
        }
        answers[Integer.bitCount(mask)] += amts[mask]
    }
    println(answers.toList().subList(1, 6).joinToString(" "))
}