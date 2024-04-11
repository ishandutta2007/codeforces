import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextLong()
    val k = jin.nextLong()
    for (answer: Long in n downTo 0L) {
        if ((((n - answer) * (n - answer + 1L)) / 2) - answer == k) {
            println(answer)
            return
        }
    }
}