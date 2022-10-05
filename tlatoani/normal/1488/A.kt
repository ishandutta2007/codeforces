fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(" ").map { it.toLong() }
        var d = y
        var pow10 = 1000000000L
        var answer = 0
        while (d >= x) {
            while (d >= x * pow10) {
                answer++
                d -= x * pow10
            }
            pow10 /= 10L
        }
        answer += d.toInt()
        println(answer)
    }
}