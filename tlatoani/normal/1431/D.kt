import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val lecturers = jin.readLine().split(" ").withIndex().map { (j, s) -> Lecturer(s.toInt(), j + 1) }
        val treeSet = TreeSet<Lecturer>(compareBy({ it.tolerance }, { it.index }))
        treeSet.addAll(lecturers)
        val answer = mutableListOf<Int>()
        answer.add(treeSet.last()!!.index)
        treeSet.remove(treeSet.last()!!)
        var curr = 1
        while (treeSet.isNotEmpty()) {
            val next = treeSet.floor(Lecturer(curr, n))
            if (next == null) {
                answer.add(treeSet.last()!!.index)
                treeSet.remove(treeSet.last()!!)
                curr++
            } else {
                answer.add(next.index)
                treeSet.remove(next)
                curr = 1
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}

data class Lecturer(val tolerance: Int, val index: Int)