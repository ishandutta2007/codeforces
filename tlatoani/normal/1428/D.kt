import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val xs = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
    val ones = Stack<Int>()
    val disp = Stack<Int>()
    val answer = mutableListOf<Pair<Int, Int>>()
    for (j in n downTo 1) {
        if (xs[j] == 1 || xs[j] == 3) {
            answer.add(Pair(j, j))
        }
        if (xs[j] == 2) {
            if (ones.isEmpty()) {
                println(-1)
                return
            }
            answer.add(Pair(ones.pop(), j))
        }
        if (xs[j] == 3) {
            if (disp.isEmpty() && ones.isEmpty()) {
                println(-1)
                return
            }
            answer.add(Pair(j, if (disp.isEmpty()) ones.pop() else disp.pop()))
        }
        if (xs[j] == 1) {
            ones.push(j)
        } else if (xs[j] > 1) {
            disp.push(j)
        }
    }
    println(answer.size)
    println(answer.joinToString("\n") { "${it.first} ${it.second}" })
}