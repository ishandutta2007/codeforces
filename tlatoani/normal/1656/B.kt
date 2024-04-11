fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val xs = readLine()!!.split(" ").map { it.toInt() }.toSet()
        out.appendln(if (xs.any { it + k in xs }) "yEs" else "nO")
    }
    print(out)
}