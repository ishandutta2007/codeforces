fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        var n = readLine()!!.toLong()
        var pow2 = 1L
        while (n % 2L == 0L) {
            n /= 2L
            pow2 *= 2L
        }
        out.appendln(when {
            n >= (2L * pow2) + 1L -> 2L * pow2
            n > 1L -> n
            else -> -1L
        })
    }
    print(out)
}