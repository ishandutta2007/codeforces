import java.util.*

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val (a, b) = readLine()!!.split(" ").map({it.toInt()})
        println(a + b)
    }
}