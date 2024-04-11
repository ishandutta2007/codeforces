fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val p = readLine()!!.split(" ").map { it.toInt() }
        val answer = IntArray(n)
        fun recur(from: Int, to: Int, d: Int) {
            if (from <= to) {
                val r = (from..to).maxBy { p[it] }!!
                answer[r] = d
                recur(from, r - 1, d + 1)
                recur(r + 1, to, d + 1)
            }
        }
        recur(0, n - 1, 0)
        println(answer.joinToString(" "))
    }
}