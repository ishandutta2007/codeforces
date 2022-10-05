fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        val j = xs.indices.minBy { xs[it] }!! + 1
        val k = xs.indices.maxBy { xs[it] }!! + 1
        out.appendln("$j $k")
    }
    print(out)
}