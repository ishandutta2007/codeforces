fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val p = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
        val correct = IntArray(n)
        for (k in 1..n) {
            correct[(k - p[k] + n) % n]++
        }
        val answer = mutableListOf<Int>()
        for (shift in (0 until n).filter { correct[it] >= n - (2 * m) }) {
            var required = n
            val seen = BooleanArray(n + 1)
            for (r in 1..n) {
                if (!seen[r]) {
                    var k = r
                    while (!seen[k]) {
                        seen[k] = true
                        k = (k + shift) % n
                        if (k == 0) {
                            k = n
                        }
                        k = p[k]
                    }
                    required--
                }
            }
            //println("shift = $shift, required = $required")
            if (required <= m) {
                answer.add(shift)
            }
        }
        out.appendln(answer.size)
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}