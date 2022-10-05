fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val cs = List(n) { readLine()!!.split(" ").map { it.toLong() } }.map { it.withIndex().map { (j, x) -> j.toLong() * x }.sum() }
        val mostCommon = cs.subList(0, 3).sorted()[1]
        val k = cs.indexOfFirst { it != mostCommon }
        println("${k + 1} ${cs[k] - mostCommon}")
    }
}