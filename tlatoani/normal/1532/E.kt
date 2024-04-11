fun main() {
    val n = readLine()!!.toInt()
    val freq = mutableMapOf<Long, Int>()
    val ay = readLine()!!.split(" ").map { it.toLong() }
    var sum = 0L
    for (k in ay) {
        freq[k] = (freq[k] ?: 0) + 1
        sum += k
    }
    val answer = mutableListOf<Int>()
    for (j in 1..n) {
        val k = ay[j - 1]
        freq[k] = freq[k]!! - 1
        if ((sum - k) % 2L == 0L && freq[(sum - k) / 2L] ?: 0 > 0) {
            answer.add(j)
        }
        freq[k] = freq[k]!! + 1
    }
    println(answer.size)
    println(answer.joinToString(" "))
}