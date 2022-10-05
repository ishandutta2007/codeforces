import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val a = IntArray(n) { jin.nextInt() }
    a.sort()
    println(a[(n - 1) / 2])
}