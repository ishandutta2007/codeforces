fun main() {
    val out = StringBuilder()
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val p = IntArray(n + 1) { it }
        var seconds = 0L
        for (j in 1..n / 2) {
            val d = (n - j).toLong()
            seconds += d * d
            val a = p[j]
            val b = p[n]
            p[j] = b
            p[n] = a
        }
        for (j in (n / 2) + 1 until n) {
            val d = (j - 1).toLong()
            seconds += d * d
            val a = p[j]
            val b = p[1]
            p[j] = b
            p[1] = a
        }
        out.appendln(seconds)
        out.appendln(p.joinToString(" ").substring(2))
        out.appendln(n - 1)
        for (j in n - 1 downTo (n / 2) + 1) {
            out.appendln("$j 1")
        }
        for (j in (n / 2) downTo 1) {
            out.appendln("$j $n")
        }
    }
    print(out)
}