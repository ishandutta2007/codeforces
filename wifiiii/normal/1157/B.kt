private fun readl() = readLine()!!
private fun readi() = readl().toInt()
private fun reads() = readl().toString()
private fun readints() = readl().split(" ").map {it.toInt()}

fun main() {
    var n = readi()
    var s = readl()
    var fl = readints()
    fun f(c: Char) = '0' + fl[c - '1']
    // greedily find first and last indices
    val i = s.indexOfFirst { c -> f(c) > c }
        .takeIf { it >= 0 } ?: s.length
    val j = s.withIndex().indexOfFirst { (j, c) -> j > i && f(c) < c }
        .takeIf { it >= 0 } ?: s.length
    // compose and write the answer
    val ans =
        s.substring(0, i) +
                s.substring(i, j).map { c -> f(c) }.joinToString("") +
                s.substring(j)
    println(ans)
}