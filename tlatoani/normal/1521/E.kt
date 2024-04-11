fun main() {
    repeat(readLine()!!.toInt()) {
        val (m, k) = readLine()!!.split(" ").map { it.toInt() }
        val freq = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
        val maxFreq = freq.max()!!
        for (n in 1..m) {
            if (m <= (n * n) - ((n / 2) * (n / 2)) && maxFreq <= ((n + 1) / 2) * n) {
                val spots = mutableListOf<Pair<Int, Int>>()
                for (y in 1 until n step 2) {
                    for (x in 0 until n step 2) {
                        spots.add(Pair(y, x))
                    }
                }
                for (y in 0 until n step 2) {
                    for (x in 0 until n step 2) {
                        spots.add(Pair(y, x))
                    }
                }
                for (y in 0 until n step 2) {
                    for (x in 1 until n step 2) {
                        spots.add(Pair(y, x))
                    }
                }
                val answer = Array(n) { IntArray(n) }
                var j = 0
                for ((k, f) in freq.withIndex().sortedByDescending { it.value }) {
                    for (x in 1..f) {
                        val (y, x) = spots[j]
                        answer[y][x] = k
                        j++
                    }
                }
                println(n)
                answer.forEach { println(it.joinToString(" ")) }
                break
            }
        }
    }
}