import java.util.*

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val (n, k) = readLine()!!.split(" ").map({it.toInt()})
        var s = String()
        for(i in 0 until k) {
            s += ('a' + i)
        }
        for(i in 0 until n) {
            print(s[(i%k)])
        }
        println()
    }
}