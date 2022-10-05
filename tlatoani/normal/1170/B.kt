import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    var first = 0
    var second = 0
    var answer = 0
    for (d in 1..jin.nextInt()) {
        val visitors = jin.nextInt()
        if (visitors >= first) {
            second = first
            first = visitors
        } else if (visitors >= second) {
            second = visitors
        } else {
            answer++
        }
    }
    println(answer)
}