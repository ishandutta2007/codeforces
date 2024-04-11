import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val p = mutableListOf<Int>()
        val tokenizer = StringTokenizer(readLine()!!)
        for (j in 1..n) {
            p.add(tokenizer.nextToken().toInt())
        }
        val joiner = StringJoiner(" ")
        var k = 0
        while (k < n) {
            var best = k
            for (j in k until p.size) {
                if (p[j] < p[best]) {
                    best = j
                }
            }
            joiner.add(p[best].toString())
            if (k == best) {
                k++
            } else {
                while (k < best - 1) {
                    joiner.add(p[k].toString())
                    k++
                }
                p[best] = p[k]
                k++
            }
        }
        println(joiner)
    }
}