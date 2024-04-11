fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val parents = listOf(0, 0) + readLine()!!.split(" ").map { it.toInt() }
        val children = Array(n + 1) { mutableListOf<Int>() }
        for (a in 2..n) {
            children[parents[a]].add(a)
        }
        val scores = listOf(0L) + readLine()!!.split(" ").map { it.toLong() }
        fun dp(a: Int, from: Int, to: Int, score: Long): Pair<Long, Long> {
            val score = score + scores[a]
            if (children[a].isEmpty()) {
                return Pair(from.toLong() * score, to.toLong() * score)
            }
            val d = children[a].size
            val newFrom = from / d
            val newTo = (to + d - 1) / d
            var base = 0L
            var differences = mutableListOf<Long>()
            for (b in children[a]) {
                val (x, y) = dp(b, newFrom, newTo, score)
                base += x
                differences += y - x
            }
            differences.sortDescending()
            return Pair(
                    base + differences.subList(0, from - (d * newFrom)).sum(),
                    base + differences.subList(0, to - (d * newFrom)).sum()
            )
        }
        val answer = dp(1, k, k, 0L).first
        println(answer)
    }
}