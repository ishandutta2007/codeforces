fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        var (s, n) = readLine()!!.split(" ").map { it.toLong() }
        val answer = mutableListOf<Long>()
        while (n > 0L) {
            n--
            if (n == 0L) {
                answer.add(s)
            } else {
                var rem = s - n
                var x = 1L
                while (rem >= 10L) {
                    rem /= 10L
                    x *= 10L
                }
                answer.add(x)
                s -= x
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}