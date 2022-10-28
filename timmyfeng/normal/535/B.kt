fun solve(x: Long, n: Long): Int = if (x >= n) 0 else 1 + solve(10 * x + 4, n) + solve(10 * x + 7, n)

fun main() {
    println(solve(0, readLine()!!.toLong()))
}