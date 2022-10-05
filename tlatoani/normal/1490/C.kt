fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toLong()
        var y = 10000L
        var answer = false
        for (x in 1..10000L) {
            while (y > 0L && (x * x * x) + (y * y * y) > n) {
                y--
            }
            if (y > 0L && (x * x * x) + (y * y * y) == n) {
                answer = true
            }
        }
        println(if (answer) "yEs" else "nO")
    }
}