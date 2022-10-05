import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    var b = 1
    for (k in 1..n) {
        val a = jin.nextInt()
        if (a % 2 == 0) {
            println(a / 2)
        } else {
            println((a + b) / 2)
            b *= -1
        }
    }
}