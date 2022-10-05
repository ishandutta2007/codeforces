import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        val amts = IntArray(3) { jin.nextInt() }
        amts.sort()
        amts[2] = min(amts[2], amts[0] + amts[1])
        println(amts.sum() / 2)
    }
}