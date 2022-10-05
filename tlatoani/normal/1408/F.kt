fun main() {
    val n = readLine()!!.toInt()
    val out = StringBuilder()
    var lambda = 0
    while (1 shl lambda <= n) {
        lambda++
    }
    lambda--
    output(out, lambda, 1)
    output(out, lambda, n - (1 shl lambda) + 1)
    println(out.count { it == '\n' })
    print(out)
}

fun output(out: StringBuilder, lambda: Int, offset: Int) {
    for (e in 1..lambda) {
        for (j in 0 until (1 shl lambda) step (1 shl e)) {
            for (k in 0 until (1 shl (e - 1))) {
                out.append(offset + j + k).append(' ').appendln(offset + j + k + (1 shl (e - 1)))
            }
        }
    }
}