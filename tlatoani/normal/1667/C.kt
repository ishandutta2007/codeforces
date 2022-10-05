fun main() {
    val n = readLine()!!.toInt()
    val m = (((2 * n) - 1) + 2) / 3
    val out = StringBuilder()
    out.appendln(m)
    for (x in 1..m) {
        val y = if (x <= (m + 1) / 2) {
            (2 * x) - 1
        } else {
            2 * (x - ((m + 1) / 2))
        }
        out.appendln("$x $y")
    }
    print(out)
}