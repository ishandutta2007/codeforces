fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        val xSum = xs[0] + xs[2] + xs[4]
        val ySum = xs[1] + xs[3] + xs[5]
        val xp = xSum % 2
        val yp = ySum % 2
        val answer = when {
            xSum == 4 && ySum == 4 -> x == 1 || y == 1
            xSum == 4 && ySum == (3 * n) - 1 -> x == 1 || y == n
            xSum == (3 * n) - 1 && ySum == 4 -> x == n || y == 1
            xSum == (3 * n) - 1 && ySum == (3 * n) - 1 -> x == n || y == n
            else -> x % 2 != xp || y % 2 != yp
        }
        println(if (answer) "YES" else "NO")
    }
}