import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val c = jin.nextInt()
    val a = IntArray(n - 1) { jin.nextInt() }
    val b = IntArray(n - 1) { jin.nextInt() }
    var le = c
    var ls = 0
    val joiner = StringJoiner(" ")
    joiner.add("0")
    for (k in 2..n) {
        val nextLS = min(le, ls) + a[k - 2]
        val nextLE = min(le, ls + c) + b[k - 2]
        joiner.add(min(nextLE, nextLS).toString())
        ls = nextLS
        le = nextLE
    }
    println(joiner)
}