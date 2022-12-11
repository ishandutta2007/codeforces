import kotlin.math.max

fun main(args: Array<String>) {
    val n = Integer.parseInt(readLine())
    for (i in 1..n) {
        val (x, y) = readLine()!!.split(" ").map(Integer::parseInt)
        val a = max(1, 1 + x - y)
        val b = x - a
        val c = y - b
        println("${a} ${b} ${c}")
    }
}