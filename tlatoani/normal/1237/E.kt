import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    var k = 1
    var b = 1
    while (k <= n) {
        if (k == n || k + 1 == n) {
            println(1)
            return
        }
        k = (2 * k) + 1 + b
        b = 1 - b
    }
    println(0)
}