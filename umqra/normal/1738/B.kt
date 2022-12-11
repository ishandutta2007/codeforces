fun check(n: Int, suffix: List<Long>): Boolean {
    if (suffix.size == 1) {
        return true
    }
    val values = suffix.zip(suffix.drop(1)).map { it.second - it.first }
    for (i in 1 until values.size) {
        if (values[i - 1] > values[i]) {
            return false
        }
    }
    val upperBound = values[0] * (n - suffix.size + 1)
    return upperBound >= suffix[0]
}

fun main() {
    val tests = readLine()!!.toInt()
    for (t in 0 until tests) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val suffix = readLine()!!.split(" ").map { it.toLong() }
        println(if (check(n, suffix)) "Yes" else "No")
    }
}