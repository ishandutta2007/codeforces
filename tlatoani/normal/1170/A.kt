import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        val x = jin.nextInt()
        val y = jin.nextInt()
        println("${min(x, y) - 1} ${max(x, y) - min(x, y) + 1} 1")
    }
}