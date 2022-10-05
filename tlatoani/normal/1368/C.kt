fun main() {
    val n = readLine()!!.toInt()
    val out = StringBuilder()
    out.appendln((3 * n) + 4)
    out.appendln("0 0")
    for (j in 0..n) {
        out.appendln("${j + 1} $j")
        out.appendln("${j + 1} ${j + 1}")
        out.appendln("$j ${j + 1}")
    }
    print(out)
}