import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val array = IntArray(n) { jin.nextInt() }
    fun attempt(ops: Int): Boolean {
        var dp = 0
        for (k in array) {
            if (k + ops < dp) {
                return false
            } else if (k > dp && k + ops < dp + m) {
                dp = k
            }
        }
        return true
    }
    var lower = 0
    var upper = m - 1
    while (upper > lower) {
        val mid = (lower + upper) shr 1
        if (attempt(mid)) {
            upper = mid
        } else {
            lower = mid + 1
        }
    }
    println(lower)
}