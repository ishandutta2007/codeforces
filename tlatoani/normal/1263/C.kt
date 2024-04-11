import java.util.*
import kotlin.math.floor
import kotlin.math.sqrt

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val sqrt = floor(sqrt(n.toDouble())).toInt()
        val answer = TreeSet<Int>()
        answer.add(0)
        for (k in 1..sqrt) {
            answer.add(k)
            answer.add(n / k)
        }
        val joiner = StringJoiner(" ")
        for (k in answer) {
            joiner.add(k.toString())
        }
        println(answer.size)
        println(joiner)
    }
}