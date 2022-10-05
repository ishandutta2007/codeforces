import kotlin.math.max
import kotlin.math.min

fun main() {
    val (n, p) = readLine()!!.split(" ").map { it.toInt() }
    val array = readLine()!!.split(" ").map { it.toInt() }.sorted()
    var lower = 1
    var upper = Int.MAX_VALUE
    val allowed = IntArray(p) { 0 }
    for (j in 0 until n) {
        lower = max(lower, array[j] - j)
        if ((j + 1) % p == 0) {
            upper = min(upper, array[j])
        }
        val r = (((array[j] - (j + 1)) % p) + p) % p
        allowed[r] = max(allowed[r], array[j] - ((j + 1) % p))
    }
    if (upper < lower) {
        println(0)
        println()
    } else {
        val answer = mutableListOf<Int>()
        for (r in 0 until p) {
            var k = max(lower, allowed[r] + 1)
            k = k + ((r - k) % p)
            if (k < max(lower, allowed[r] + 1)) {
                k += p
            }
            while (k <= upper) {
                answer.add(k)
                k += p
            }
        }
        answer.sort()
        println(answer.size)
        println(answer.joinToString(" "))
    }
}