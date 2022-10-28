fun main() {
    val n = readLine()!!.toInt()

    val freq = mutableMapOf<String, Int>()
    for (i in 0 until n) {
        val row = readLine()!!
        freq[row] = freq.getOrDefault(row, 0) + 1
    }

    println(freq.values.maxOrNull())
}