import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextLong()
    val k = jin.nextLong()
    println(if ((n / k) % 2L == 1L) "YES" else "NO")
}