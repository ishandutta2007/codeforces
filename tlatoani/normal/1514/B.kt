const val MOD = 1000000007L

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toLong() }
        var answer = 1L
        for (j in 1L..k) {
            answer *= n
            answer %= MOD
        }
        println(answer)
    }
}