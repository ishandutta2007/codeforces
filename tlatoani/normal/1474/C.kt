import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    val needed = IntArray(1000001)
    val toUnset = mutableListOf<Int>()
    cases@for (c in 1..jin.readLine().toInt()) {
        jin.readLine()
        val ay = jin.readLine().split(" ").map { it.toInt() }.toMutableList()
        ay.sortDescending()
        for (j in 1 until ay.size) {
            val operations = mutableListOf<Pair<Int, Int>>()
            var prev = ay[0] + ay[j]
            for (a in ay) {
                if (needed[a] > 0) {
                    needed[a]--
                } else {
                    needed[prev - a]++
                    operations.add(Pair(a, prev - a))
                    toUnset.add(prev - a)
                    prev = a
                }
            }
            var works = true
            for (a in toUnset) {
                if (needed[a] != 0) {
                    works = false
                    needed[a] = 0
                }
            }
            toUnset.clear()
            if (works) {
                out.appendln("YES")
                out.appendln(ay[0] + ay[j])
                for ((a, b) in operations) {
                    out.appendln("$a $b")
                }
                continue@cases
            }
        }
        out.appendln("NO")
    }
    print(out)
}