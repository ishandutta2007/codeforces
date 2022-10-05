fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        var answer = "NO"
        fun recur(j: Int, sum: Int, nonzero: Boolean) {
            if (j == n) {
                if (nonzero && sum == 0) {
                    answer = "YES"
                }
            } else {
                recur(j + 1, sum - xs[j], true)
                recur(j + 1, sum, nonzero)
                recur(j + 1, sum + xs[j], true)
            }
        }
        recur(0, 0, false)
        println(answer)
    }
}