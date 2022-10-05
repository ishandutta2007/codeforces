import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    val w = tokenizer.nextToken().toLong()
    var mexico = 0L
    var minimo = 0L
    var coriente = 0L
    tokenizer = StringTokenizer(readLine()!!)
    for (j in 1..n) {
        coriente += tokenizer.nextToken().toLong()
        mexico = max(mexico, coriente)
        minimo = min(minimo, coriente)
    }
    println(max(0L, w - (mexico - minimo) + 1L))
}