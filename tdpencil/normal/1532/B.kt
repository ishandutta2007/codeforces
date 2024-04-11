import java.util.*

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val (a, b, k) = readLine()!!.split(" ").map({it.toLong()})
        if(k % 2 == 0L) {
            println((a-b)*(k/2))
        } else {
            println((a-b)*(k/2)+a)
        }
    }
}