import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val k = jin.nextInt()
    val bits = IntArray(k + 1)
    for (i in 1..n) {
        bits[jin.nextInt()]++
    }
    println(n - (bits.fold(0) { acc, b -> acc + (b and 1) } / 2))
}