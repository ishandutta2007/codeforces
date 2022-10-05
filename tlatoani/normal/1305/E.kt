import java.util.*

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    var m = -line.substring(six + 1).toInt()
    for (k in 1..n) {
        m += (k - 1) / 2
    }
    if (m < 0) {
        println(-1)
        return
    }
    var beta = n
    var alpha = 0
    while (beta > 0) {
        val change = (beta - 1) / 2
        if (m >= change) {
            m -= change
            beta--
            alpha++
        } else {
            break
        }
    }
    var joiner = StringJoiner(" ")
    if (beta != 0) {
        var last = beta
        beta--
        while (m > 0) {
            if (last % 2 == 1) {
                m--
            }
            last++
        }
        for (j in 1..beta) {
            joiner.add(j.toString())
        }
        joiner.add(last.toString())
    }
    for (j in 1..alpha) {
        joiner.add(((j * 100000) + 1).toString())
    }
    println(joiner)
}