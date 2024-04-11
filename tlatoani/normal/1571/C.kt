import kotlin.math.max
import kotlin.math.min

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var maxK = 200000
        var minK = 0
        repeat(n) {
            val (s, t, r) = readLine()!!.split(" ").map { it.reversed() }
            var k = 0
            while (k < s.length && k < t.length && s[k] == t[k]) {
                k++
            }
            if (r.toInt() == 1) {
                maxK = min(maxK, k)
            } else {
                minK = max(minK, k + 1)
            }
        }
        out.appendln(max(0, maxK - minK + 1))
        out.appendln((minK..maxK).joinToString(" "))
    }
    print(out)
}