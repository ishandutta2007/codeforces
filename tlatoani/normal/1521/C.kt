fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        fun query(t: Int, j: Int, k: Int, x: Int): Int {
            println("? $t $j $k $x")
            return readLine()!!.toInt()
        }
        val important = mutableListOf<Int>()
        for (j in 1..n step 2) {
            val r = query(2, j, if (j == n) 1 else (j + 1), 1)
            if (r <= 2) {
                important.add(j)
                if (j != n) {
                    important.add(j + 1)
                }
            }
        }
        var k = 0
        for (j in important) {
            if (query(2, j, if (j == n) 1 else (j + 1), 1) == 1) {
                k = j
            }
        }
        val answer = IntArray(n + 1)
        answer[k] = 1
        for (j in 1..n) {
            if (j != k) {
                answer[j] = query(1, k, j, n - 1)
            }
        }
        println("! " + answer.joinToString(" ").substring(2))
    }
}