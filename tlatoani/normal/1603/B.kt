fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(" ").map { it.toLong() }
        if (x > y) {
            out.appendln(x + y)
        } else {
            val z = y - (y % x)
            out.appendln((y + z) / 2L)
        }
    }
    print(out)
}