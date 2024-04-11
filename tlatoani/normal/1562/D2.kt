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
            val removed = mutableListOf<Int>()
            if (sums[r] == sums[l]) {

            } else {
                if (r % 2 == l % 2) {
                    removed.add(r)
                    r--
                }
                val delta = sums[r] - sums[l]
                //println("sums[l] = ${sums[l]}, sums[r] = ${sums[r]}, vareage  = ${(sums[l] + sums[r]) / 2}, new = ${sums[l] + (delta / 2)}")
                val k = appearances[sums[l] + (delta / 2)].floor(r)
                removed.add(k + 1)
            }
            out.appendln(removed.size)
            out.appendln(removed.joinToString(" "))
        }
    }
    print(out)
}