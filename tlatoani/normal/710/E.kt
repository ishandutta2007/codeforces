import kotlin.math.min

fun main() {
    val (n, x, y) = readLine()!!.split(" ").map { it.toLong() }
    fun minChanges(z: Long): Int {
        var z = z
        var res = 0
        while (z > 0L) {
            if (z and 1L == 1L) {
                if (z and 3L == 3L) {
                    z++
                } else {
                    z--
                }
                res++
            }
            z = z shr 1
        }
        return res
    }
    var answer = Long.MAX_VALUE
    for (e in 0..29) {
        answer = min(answer, (e.toLong() * y) + (((n shr e) + minChanges(n % (1L shl e))) * x))
    }
    println(answer)
}