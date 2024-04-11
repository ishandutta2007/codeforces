fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        var answer = "NO"
        for (j in 1 until n) {
            if (xs[j] % 2 == xs[j - 1] % 2) {
                answer = "YES"
            }
        }
        println(answer)
    }
}