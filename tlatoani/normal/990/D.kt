import kotlin.math.max
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val (n, a, b) = readLine()!!.split(" ").map { it.toInt() }
    if (a != 1 && b != 1 || ((n == 2 || n == 3) && a == 1 && b == 1)) {
        println("NO")
    } else {
        println("YES")
        for (x in 0 until n) {
            println(CharArray(n) { y -> if (x != y && ((b == 1) == (abs(x - y) == 1 && min(x, y) >= max(a, b) - 1))) '1' else '0' })
        }
    }
}