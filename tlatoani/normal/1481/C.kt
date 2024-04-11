import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val curr = intArrayOf(0) + jin.readLine().split(" ").map { it.toInt() }.toIntArray()
        val goal = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
        val painters = jin.readLine().split(" ").map { it.toInt() }
        val rem = IntArray(n + 1)
        for (j in 0 until m) {
            rem[painters[j]]++
        }
        val toColor = Array(n + 1) { mutableListOf<Int>() }
        val placeholder = IntArray(n + 1)
        val disp = TreeSet<Int>()
        for (j in 1..n) {
            placeholder[goal[j]] = j
            if (curr[j] != goal[j]) {
                toColor[goal[j]].add(j)
            }
            disp.add(j)
        }
        val answer = IntArray(m)
        for (j in 0 until m) {
            if (toColor[painters[j]].isNotEmpty()) {
                answer[j] = toColor[painters[j]].last()
                curr[answer[j]] = painters[j]
                toColor[painters[j]].removeAt(toColor[painters[j]].lastIndex)
            } else if (placeholder[painters[j]] != 0) {
                answer[j] = placeholder[painters[j]]
            } else {
                while (disp.isNotEmpty()) {
                    val k = disp.first()!!
                    if (curr[k] != goal[k] || rem[goal[k]] > toColor[goal[k]].size) {
                        answer[j] = k
                        if (curr[k] == goal[k]) {
                            toColor[goal[k]].add(k)
                        }
                        curr[k] = painters[j]
                        break
                    } else {
                        disp.remove(k)
                    }
                }
            }
            rem[painters[j]]--
        }
        if (answer.all { it != 0 } && toColor.all { it.isEmpty() }) {
            out.appendln("YES")
            out.appendln(answer.joinToString(" "))
        } else {
            out.appendln("NO")
        }
    }
    print(out)
}