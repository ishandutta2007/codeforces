fun main() {
    val line = readLine()!!.split(" ")
    val n = line[0].toInt()
    val m = line[1].toLong()
    var dpPrev = Array(n + 1) { Array(3) { LongArray(n + 1) } }
    var dpNext = Array(n + 1) { Array(3) { LongArray(n + 1) } }
    dpNext[1][2][1] = 1L
    for (k in 2..n) {
        val temp = dpNext
        dpNext = dpPrev
        dpPrev = temp
        for (x in 1..k) {
            for (j in 1..x) {
                dpNext[x][2][j] = dpPrev[x - 1][0][0]
            }
            var curr = 0L
            for (j in 1..x) {
                curr += dpPrev[x - 1][1][j - 1]
                curr %= m
                dpNext[x][1][j] = curr
            }
            dpNext[x - 1][0][0] = curr
            var curr1 = 0L
            var curr2 = dpPrev[x - 1][2].sum() % m
            for (j in 1..x) {
                curr1 += dpPrev[x - 1][2][j - 1]
                curr1 %= m
                curr2 -= dpPrev[x - 1][2][j - 1]
                curr2 %= m
                dpNext[x][1][j] += curr1
                dpNext[x][1][j] %= m
                dpNext[x][2][j] += curr2
                dpNext[x][2][j] %= m
            }
            dpNext[x - 1][0][0] += curr1
            dpNext[x - 1][0][0] %= m
        }
    }
    val answer = ((dpNext.map { it[1].sum() + it[2].sum() }.sum() % m) + m) % m
    println(answer)
}