fun main() {
    val (n, k, x) = readLine()!!.split(" ").map { it.toInt() }
    val pow = ("1" + "0".repeat(k)).toLong(x)
    val ay = listOf(0L) + readLine()!!.split(" ").map { it.toLong() }
    val prefixes = LongArray(n + 1)
    for (j in 1..n) {
        prefixes[j] = prefixes[j - 1] or ay[j]
    }
    val suffixes = LongArray(n + 2)
    for (j in n downTo 1) {
        suffixes[j] = ay[j] or suffixes[j + 1]
    }
    println((1..n).map { j -> prefixes[j - 1] or (pow * ay[j]) or suffixes[j + 1] }.max())
}