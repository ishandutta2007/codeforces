const val MOD = 1000000007L

fun main() {
    val (n, x, index) = readLine()!!.split(" ").map { it.toInt() }
    var above = 0
    var below = 0
    var left = 0
    var right = n
    while (left < right) {
        val middle = (left + right) / 2
        if (middle < index) {
            below++
        } else if (middle > index) {
            above++
        }
        if (middle <= index) {
            left = middle + 1
        } else {
            right = middle
        }
    }
    var answer = 1L
    for (j in 0 until above) {
        answer *= (n - x - j).toLong()
        answer %= MOD
    }
    for (j in 0 until below) {
        answer *= (x - 1 - j).toLong()
        answer %= MOD
    }
    for (j in 1..n - above - below - 1) {
        answer *= j.toLong()
        answer %= MOD
    }
    println(answer)
}