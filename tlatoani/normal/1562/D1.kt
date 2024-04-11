import java.util.*

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (n, q) = readLine()!!.split(" ").map { it.toInt() }
        val s = " " + readLine()!!
        val sums = IntArray(n + 1)
        for (j in 1..n) {
            sums[j] = sums[j - 1]
            if ((s[j] == '+') == (j % 2 == 0)) {
                sums[j]++
            } else {
                sums[j]--
            }
        }
        val m = sums.min()!!
        val appearances = Array(n + 1) { TreeSet<Int>() }
        for (j in 0..n) {
            sums[j] -= m
            appearances[sums[j]].add(j)
        }
        repeat(q) {
            var (l, r) = readLine()!!.split(" ").map { it.toInt() }
            l--
            if (sums[r] == sums[l]) {
                out.appendln(0)
            } else {
                if (r % 2 == l % 2) {
                    out.appendln(2)
                } else {
                    out.appendln(1)
                }
            }
        }
    }
    print(out)
}