fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
        if (n % 2 == 0) {
            if (k % 2 == 0 && (m % 2 == 0 || 2 * k <= n * (m - 1))) {
                println("YES")
            } else {
                println("NO")
            }
        } else {
            if (k >= m / 2 && (k - (m / 2)) % 2 == 0) {
                println("YES")
            } else {
                println("NO")
            }
        }
    }
}