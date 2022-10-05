fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val shirts = readLine()!!.split(" ").map { it.toInt() }
        val initial = mutableMapOf<Int, Int>()
        for (j in 0 until n step 2) {
            initial[shirts[j]] = (initial[shirts[j]] ?: 0) + 1
        }
        val sorted = shirts.sorted()
        val final = mutableMapOf<Int, Int>()
        for (j in 0 until n step 2) {
            final[sorted[j]] = (final[sorted[j]] ?: 0) + 1
        }
        println(if (initial == final) "yEs" else "nO")
    }
}