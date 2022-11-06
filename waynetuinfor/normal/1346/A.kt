import java.util.*

fun main() {
    var t = readLine()!!.toInt()
    while (t-- > 0) {
        val (n, k) = readLine()!!.split(" ").map{ it.toInt() }
        val k4 = 1 + k + k * k + k * k * k
        val n1 = n / k4
        println(n1.toString() + " " + (n1 * k).toString() + " " + (n1 * k * k).toString() + " " + (n1 * k * k * k).toString())
    }
}