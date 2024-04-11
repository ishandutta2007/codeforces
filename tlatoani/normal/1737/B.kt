fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (l, r) = readLine()!!.split(" ").map { it.toLong() }
        val answer = solve(r) - solve(l - 1L)
        out.appendln(answer)
    }
    print(out)
}

fun solve(to: Long): Long {
    val s = sqrt(to)
    var res = 3L * s
    for (x in s - 1L..s) {
        if (x > 0L) {
            for (d in 0L..2L) {
                if (x * (x + d) > to) {
                    res--
                }
            }
        }
    }
    return res
}

fun sqrt(x: Long): Long {
    var upper = 1000000000L
    var lower = 0L
    while (upper > lower) {
        val mid = (upper + lower) / 2L
        if (mid * mid >= x) {
            upper = mid
        } else {
            lower = mid + 1L
        }
    }
    return upper
}