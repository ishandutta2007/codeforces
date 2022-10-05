import kotlin.math.pow

fun main() {
    val (m, n) = readLine()!!.split(" ").map { it.toInt() }
    var answer = m.toDouble()
    for (k in 0 until m) {
        answer -= (k.toDouble() / m.toDouble()).pow(n)
    }
    println(answer)
}