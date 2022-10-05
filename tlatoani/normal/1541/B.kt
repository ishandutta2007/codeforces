fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = listOf(0L) + readLine()!!.split(" ").map { it.toLong() }
        var answer = 0L
        for (j in 1..n) {
            val x = ay[j]
            if (x <= 320L) {
                for (y in 1L until x) {
                    if ((x * y) - j.toLong() in 1..n && ay[(x * y).toInt() - j] == y) {
                        answer++
                    }
                }
            } else {
                for (z in x..2L * n.toLong() step x) {
                    if (z / x < x && z - j.toLong() in 1..n && ay[z.toInt() - j] == z / x) {
                        answer++
                    }
                }
            }
        }
        println(answer)
    }
}