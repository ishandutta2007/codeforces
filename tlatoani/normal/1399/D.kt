import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val s = jin.readLine()
        val answer = IntArray(n)
        val treeSet0 = TreeSet<Int>()
        val treeSet1 = TreeSet<Int>()
        var rem = 0
        for (j in s.indices) {
            if (s[j] == '0') {
                val t = if (treeSet0.isEmpty()) {
                    rem++
                    rem
                } else {
                    treeSet0.first()
                }
                treeSet0.remove(t)
                answer[j] = t
                treeSet1.add(t)
            } else {
                val t = if (treeSet1.isEmpty()) {
                    rem++
                    rem
                } else {
                    treeSet1.first()
                }
                treeSet1.remove(t)
                answer[j] = t
                treeSet0.add(t)
            }
        }
        out.appendln(answer.max())
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}