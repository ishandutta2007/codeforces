fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
        val freqs = IntArray(n + 1)
        for (x in xs) {
            freqs[x]++
        }
        val m = (1..n).maxBy { freqs[it] }!!
        for (j in 0 until n) {
            if (xs[j] == m) {
                xs[j] = 0
            }
        }
        val indices = xs.indices.sortedBy { xs[it] }
        val last = IntArray(freqs[m]) { -1 }
        val answer = IntArray(n)
        for ((j, ix) in indices.withIndex()) {
            if (j >= freqs[m]) {
                answer[last[j % freqs[m]]] = xs[ix]
            }
            last[j % freqs[m]] = ix
        }
        for (j in last.indices) {
            answer[last[j]] = xs[indices[j]]
        }
        for (j in 0 until n) {
            if (answer[j] == 0) {
                answer[j] = m
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}