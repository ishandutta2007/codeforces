fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ps = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
        val sums = Array(n + 1) { LongArray(n + 1) }
        for (j in 1..n) {
            for (k in 1..n) {
                sums[j][k] = sums[j][k - 1]
                if (ps[k] < ps[j]) {
                    sums[j][k]++
                }
            }
        }
        var answer = 0L
        for (b in 1..n) {
            for (c in b + 1..n) {
                answer += sums[c][b - 1] * (sums[b][n] - sums[b][c])
            }
        }
        println(answer)
    }
}