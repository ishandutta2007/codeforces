fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, a, b) = readLine()!!.split(" ").map { it.toLong() }
        var pow = 1L
        var answer = "nO"
        while (pow <= n) {
            if ((n - pow) % b == 0L) {
                answer = "yEs"
                break
            }
            if (a == 1L) {
                break
            }
            pow *= a
        }
        println(answer)
    }
}