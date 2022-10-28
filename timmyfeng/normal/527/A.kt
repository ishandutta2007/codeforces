fun solve(a: Long, b: Long): Long = if (b == 0L) 0 else solve(b, a % b) + a / b

fun main() {
    val (a, b) = readLine()!!.split(" ").map { it.toLong() }
    println(solve(a, b))
}