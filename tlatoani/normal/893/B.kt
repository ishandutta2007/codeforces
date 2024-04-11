fun main() {
    val n = readLine()!!.toInt()
    var answer = 1
    for (k in 2..10) {
        val b = (1 shl ((2 * k) - 1)) - (1 shl (k - 1))
        if (n % b == 0) {
            answer = b
        } else if (b > n) {
            println(answer)
            return
        }
    }
}