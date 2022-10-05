import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    if (n % 2 == 0) {
        println("First")
        val belongs = (1..n).joinToString(" ")
        println("$belongs $belongs")
    } else {
        println("Second")
        val pairs = Array(n) { mutableListOf<Int>() }
        val tokenizer = StringTokenizer(readLine()!!)
        val edges = Array(n) { mutableListOf<Int>() }
        for (j in 1..2 * n) {
            val k = tokenizer.nextToken().toInt() - 1
            pairs[k].add(j)
            edges[j % n].add(k)
        }
        val cycles0 = mutableListOf<List<Int>>()
        val cycles1 = mutableListOf<List<Int>>()
        val seen = BooleanArray(n)
        var overall = 0L
        for (j in 0 until n) {
            if (!seen[j]) {
                seen[j] = true
                val cycle0 = mutableListOf(pairs[j][0])
                val cycle1 = mutableListOf(pairs[j][1])
                if (cycle0[0] % n != cycle1[0] % n) {
                    var k = j
                    while (true) {
                        var (a, b) = edges[cycle0.last() % n]
                        k = a + b - k
                        if (k == j) {
                            break
                        }
                        seen[k] = true
                        if (pairs[k][0] % n == cycle0.last() % n) {
                            cycle1.add(pairs[k][0])
                            cycle0.add(pairs[k][1])
                        } else {
                            cycle0.add(pairs[k][0])
                            cycle1.add(pairs[k][1])
                        }
                    }
                }
                for (d in cycle0) {
                    overall += d.toLong()
                }
                cycles0.add(cycle0)
                cycles1.add(cycle1)
            }
        }
        var needSwitch = overall % (2 * n).toLong() != 0L
        val joiner = StringJoiner(" ")
        for (j in cycles0.indices) {
            if (needSwitch && cycles0[j].size % 2 == 1) {
                joiner.add(cycles1[j].joinToString(" "))
                needSwitch = false
            } else {
                joiner.add(cycles0[j].joinToString(" "))
            }
        }
        println(joiner)
    }
}