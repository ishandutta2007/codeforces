import java.util.*

val readQueue = ArrayDeque<String>()

fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let { readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getDouble() = getInput().toDouble()
fun getString() = getInput()
fun getLong() = getInput().toLong()

fun main() {
    var T = getInt()

    testcase@ while (T-- > 0) {

        val n = getInt()
        val b = readLine()!!.split(" ").map { it.toInt() }

        val s = TreeSet<Int>()
        for (i in 1..2 * n) s.add(i);
        for (i in b) s.remove(i)

        val a = MutableList(2 * n) { 0 }
        for (i in 0 until n) {
            a[i * 2] = b[i]
            val t = s.higher(b[i])
            if (t == null) {
                println("-1")
                continue@testcase
            }
            s.remove(t)
            a[i * 2 + 1] = t
        }

        a.forEach { print("$it ") }
        println()

    }
}