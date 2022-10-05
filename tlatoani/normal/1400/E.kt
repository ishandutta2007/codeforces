import java.util.*
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val ay = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
    val left = IntArray(n + 1)
    val right = IntArray(n + 1)
    val stack = Stack<Int>()
    for (j in 1..n) {
        if (stack.isNotEmpty() && ay[j] < ay[stack.peek()]) {
            var k = stack.pop()
            while (stack.isNotEmpty() && ay[j] < ay[stack.peek()]) {
                right[stack.peek()] = k
                k = stack.pop()
            }
            left[j] = k
        }
        stack.push(j)
    }
    while (stack.size > 1) {
        val j = stack.pop()
        right[stack.peek()] = j
    }
    fun recur(from: Int, mid: Int, to: Int, prev: Int): Int {
        var res = ay[mid] - prev
        if (left[mid] != 0) {
            res += recur(from, left[mid], mid - 1, ay[mid])
        }
        if (right[mid] != 0) {
            res += recur(mid + 1, right[mid], to, ay[mid])
        }
        return min(res, to - from + 1)
    }
    println(recur(1, stack.peek(), n, 0))
}