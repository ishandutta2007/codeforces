import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val ys = IntArray((2 * n) + 1)
    val line = readLine()!!
    for (i in 0 until 2 * n) {
        ys[i + 1] = ys[i] + if (line[i % n] == '(') 1 else -1
    }
    if (ys[n] != 0) {
        println(0)
        println("1 1")
        return
    }
    val low = ys.min()!!
    val sums = Array(3) { IntArray((2 * n) + 1) }
    //println("ys = ${ys.contentToString()}")
    //println("low = $low")
    for (i in 1..2 * n) {
        for (j in 0..2) {
            sums[j][i] = sums[j][i - 1]
        }
        if (ys[i] - low <= 2) {
            sums[ys[i] - low][i]++
        }
    }
    /*for (j in 0..2) {
        println("sums[$j] = ${sums[j].contentToString()}")
    }*/
    val last = IntArray(2)
    val nearest = Array(2) { IntArray(n + 1) }
    for (i in 2 * n downTo 1) {
        if (ys[i] - low <= 1) {
            last[ys[i] - low] = i
        }
        if (i <= n) {
            for (j in 0..1) {
                nearest[j][i] = last[j]
            }
        }
    }
    /*for (j in 0..1) {
        println("nearest[$j] = ${nearest[j].contentToString()}")
    }*/
    var answer = sums[0][n]
    var al = 1
    var ar = 1
    for (i in 1..n) {
        if (line[i - 1] == '(') {
            var j = min(nearest[0][i], nearest[1][i])
            var pos = sums[0][n] + sums[2][j - 1] - sums[2][i - 1]
            if (pos > answer) {
                answer = pos
                al = i
                ar = j
            }
            if (nearest[1][i] < nearest[0][i]) {
                j = nearest[0][i]
                pos = sums[1][j - 1] - sums[1][i - 1]
                if (pos > answer) {
                    answer = pos
                    al = i
                    ar = j
                }
            }
        }
    }
    println(answer)
    println("$al ${((ar - 1) % n) + 1}")
}