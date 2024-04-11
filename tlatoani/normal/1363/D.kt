import java.util.*

fun main() {
    fun query(ixs: Iterable<Int>): Int {
        var amt = 0
        val joiner = StringJoiner(" ")
        for (ix in ixs) {
            amt++
            joiner.add(ix.toString())
        }
        println("? $amt $joiner")
        return readLine()!!.toInt()
    }
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val subsets = Array(k) {
            val split = readLine()!!.split(" ")
            split.subList(1, split.size).map { it.toInt() }.toSet()
        }
        val mexico = query(1..n)
        var l = 1
        var r = n
        while (r > l) {
            val mid = (l + r) / 2
            if (query(l..mid) == mexico) {
                r = mid
            } else {
                l = mid + 1
            }
        }
        val answer = IntArray(k) { if (l in subsets[it]) query((1..n).toSet().minus(subsets[it])) else mexico }
        println("! " + answer.joinToString(" "))
        readLine()
    }
}

/*
1
8 3
3 1 7 4
2 2 5
2 6 3

1
8 3
3 1 7 4
2 2 5
2 8 3









1 4 6 2 3 8 5 4
 */