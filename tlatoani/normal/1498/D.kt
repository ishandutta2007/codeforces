import java.util.*

/// el psy kongroo

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val answer = IntArray(m + 1) { -1 }
    answer[0] = 0
    val treeSet = TreeSet<Int>(reverseOrder())
    treeSet.add(0)
    val toAdd = mutableListOf<Int>()
    for (j in 1..n) {
        val (t, x, y) = readLine()!!.split(" ").map { it.toLong() }
        for (k in treeSet) {
            var u = k.toLong()
            for (j2 in 1L..y) {
                u = if (t == 1L) operation1(u, x) else operation2(u, x)
                if (u <= m && answer[u.toInt()] == -1) {
                    answer[u.toInt()] = j
                    toAdd.add(u.toInt())
                } else {
                    break
                }
            }
        }
        treeSet.addAll(toAdd)
        toAdd.clear()
    }
    println(answer.joinToString(" ").substring(2))
}

fun operation1(k: Long, x: Long) = k + ((x + 99999L) / 100000L)
fun operation2(k: Long, x: Long) = ((k * x) + 99999L) / 100000L