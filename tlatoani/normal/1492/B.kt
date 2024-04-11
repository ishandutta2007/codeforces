import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val p = jin.readLine().split(" ").map { it.toInt() }.reversed()
        val suffixes = IntArray(n + 1)
        for (j in n - 1 downTo 0) {
            suffixes[j] = max(p[j], suffixes[j + 1])
        }
        val stack = Stack<Int>()
        val answer = mutableListOf<Int>()
        for (j in 0 until n) {
            stack.push(p[j])
            if (p[j] == suffixes[j]) {
                answer.addAll(stack.reversed())
                stack.clear()
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}