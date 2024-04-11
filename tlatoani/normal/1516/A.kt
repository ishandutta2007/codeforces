import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val array = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
        var rem = k
        for (j in 0 until n) {
            val d = min(rem, array[j])
            array[j] -= d
            rem -= d
        }
        array[n - 1] += k - rem
        println(array.joinToString(" "))
    }
}