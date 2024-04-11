import java.util.*
import kotlin.math.abs

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!.map { it == '(' || it == ')' }
        val prefixes = IntArray(s.size + 1)
        val deque = ArrayDeque<Boolean>()
        for (j in 1..s.size) {
            val x = s[j - 1]
            if (deque.isNotEmpty() && deque.last == x) {
                deque.removeLast()
            } else {
                deque.addLast(x)
            }
            prefixes[j] = if (deque.isEmpty()) 0 else { (if (deque.first) 1 else -1) * deque.size }
        }
        val q = readLine()!!.toInt()
        repeat(q) {
            val (l, r) = readLine()!!.split(" ").map { it.toInt() }
            out.appendln(abs(prefixes[r] - prefixes[l - 1]) / 2)
        }
    }
    print(out)
}