fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val d = line.substring(0, six).toLong()
        val m = line.substring(six + 1).toLong()
        var e = 0
        while (d >= (1L shl e)) {
            e++
        }
        e--
        val rem = d - (1L shl e) + 1L
        e--
        var answer = 1L
        for (k in 0..e) {
            answer *= (1L shl k) + 1L
            answer %= m
        }
        answer = ((((rem * answer) + answer - 1L) % m) + m) % m
        println(answer)
    }
}