fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!.map { it - '0' }
        val x = s.sum()
        if ((m.toLong() * x.toLong()) % n.toLong() != 0L) {
            out.appendln(-1)
        } else {
            val needed = ((m.toLong() * x.toLong()) / n.toLong()).toInt()
            var possible = -1
            var curr = s.subList(0, m).sum()
            for (j in 0 until n) {
                if (curr == needed) {
                    possible = j
                    break
                }
                curr -= s[j]
                curr += s[(j + m) % n]
            }
            if (possible + m <= n) {
                out.appendln(1)
                out.appendln("${possible + 1} ${possible + m}")
            } else {
                out.appendln(2)
                out.appendln("1 ${(possible + m) - n}")
                out.appendln("${possible + 1} $n")
            }
        }
    }
    print(out)
}