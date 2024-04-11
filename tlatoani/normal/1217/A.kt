import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        var s = jin.nextLong()
        val i = jin.nextLong()
        var e = jin.nextLong()
        if (s + e <= i) {
            println(0)
        } else {
            e -= max(0L, i + 1 - s)
            s += max(0L, i + 1 - s)
            println((s + e) - max(s, ((s + e + i) / 2L) + 1L) + 1L)
        }
    }
}