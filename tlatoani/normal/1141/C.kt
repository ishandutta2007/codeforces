import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val p = LongArray(n)
    for (j in 1 until n) {
        p[j] = p[j - 1] + tokenizer.nextToken().toLong()
    }
    if (p.max()!! - p.min()!! != (n - 1).toLong() || p.toSet().size != n) {
        println(-1)
        return
    }
    val m = p.min()!!
    for (j in 0 until n) {
        p[j] += 1L - m
    }
    println(p.joinToString(" ", "", ""))
}