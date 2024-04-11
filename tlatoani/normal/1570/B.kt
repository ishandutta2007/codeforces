import kotlin.math.max
import kotlin.math.min

fun main() {
    val k1 = readLine()!!.toInt()
    val k2 = readLine()!!.toInt()
    val a1 = readLine()!!.toInt()
    val a2 = readLine()!!.toInt()
    val n = readLine()!!.toInt()
    val minimo = calc2(a1, a2, k1, k2, n)
    val maximo = max(calc1(a1, a2, k1, k2, n), calc1(a2, a1, k2, k1, n))
    println("$minimo $maximo")
}

fun calc1(a1: Int, a2: Int, k1: Int, k2: Int, n: Int): Int {
    var res = 0
    res += min(k1, n / a1)
    if (n > k1 * a1) {
        res += min(k2, (n - (k1 * a1)) / a2)
    }
    return res
}

fun calc2(a1: Int, a2: Int, k1: Int, k2: Int, n: Int): Int {
    return max(0, n - (k1 * (a1 - 1)) - (k2 * (a2 - 1)))
}