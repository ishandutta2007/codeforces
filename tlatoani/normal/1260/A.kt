import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    for (r in 1..jin.nextInt()) {
        val c = jin.nextInt()
        val s = jin.nextInt()
        val radiators = IntArray(c)
        for (j in 0 until s) {
            radiators[j % c]++
        }
        var answer = 0
        for (j in 0 until c) {
            answer += radiators[j] * radiators[j]
        }
        println(answer)
    }
}