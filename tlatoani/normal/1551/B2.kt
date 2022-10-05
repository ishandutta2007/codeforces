fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val numbers = readLine()!!.split(" ").map { it.toInt() }
        val freq = IntArray(n + 1)
        val toUse = mutableListOf<Int>()
        for (j in 0 until n) {
            if (freq[numbers[j]] < k) {
                freq[numbers[j]]++
                toUse.add(j)
            }
        }
        toUse.sortBy { numbers[it] }
        while (toUse.size % k != 0) {
            toUse.removeAt(toUse.lastIndex)
        }
        val answer = IntArray(n)
        for ((j2, j) in toUse.withIndex()) {
            answer[j] = (j2 % k) + 1
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}