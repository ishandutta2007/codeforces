import java.lang.StringBuilder
import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    var tokenizer = StringTokenizer(readLine()!!)
    val a = LongArray(n) { tokenizer.nextToken().toLong() }
    var answer = a.sum()
    val q = readLine()!!.toInt()
    val b = LongArray(n)
    val map = mutableMapOf<Pair<Int, Int>, Int>()
    val out = StringBuilder()
    for (j in 1..q) {
        tokenizer = StringTokenizer(readLine()!!)
        val s = tokenizer.nextToken().toInt() - 1
        val t = tokenizer.nextToken().toInt()
        val u = tokenizer.nextToken().toInt() - 1
        map.remove(Pair(s, t))?.let {
            b[it]--
            if (b[it] < a[it]) {
                answer++
            }
        }
        if (u >= 0) {
            if (b[u] < a[u]) {
                answer--
            }
            b[u]++
            map[Pair(s, t)] = u
        }
        out.appendln(answer)
    }
    print(out)
}