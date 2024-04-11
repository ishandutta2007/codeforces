import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val xs = jin.nextInt()
    val ys = jin.nextInt()
    val n = jin.nextInt()
    val x = IntArray(n)
    val y = IntArray(n)
    for (j in 0 until n) {
        x[j] = jin.nextInt()
        y[j] = jin.nextInt()
    }
    val dp = IntArray(1 shl n) { 100000000 }
    val dpPrev = IntArray(1 shl n) { -1 }
    dp[0] = 0
    for (mask in 1 until (1 shl n)) {
        var j = 0
        while (((mask shr j) and 1) == 0) {
            j++
        }
        dp[mask] = ((x[j] - xs) * (x[j] - xs)) + ((y[j] - ys) * (y[j] - ys)) + dp[mask - (1 shl j)]
        for (k in j + 1 until n) {
            if (((mask shr k) and 1) != 0) {
                val value = ((x[j] - x[k]) * (x[j] - x[k])) + ((y[j] - y[k]) * (y[j] - y[k])) + dp[mask - (1 shl j) - (1 shl k)]
                if (value < dp[mask]) {
                    dp[mask] = value
                    dpPrev[mask] = k
                }
            }
        }
    }
    val way = mutableListOf<Int>()
    var mask = (1 shl n) - 1
    for (j in 0 until n) {
        if (((mask shr j) and 1) != 0) {
            val k = dpPrev[mask]
            //println("j = $j, k = $k")
            way.add(0)
            way.add(j + 1)
            if (k != -1) {
                way.add(k + 1)
            }
            mask -= 1 shl j
            if (k != -1) {
                mask -= 1 shl k
            }
        }
    }
    way.add(0)
    var answer = 0
    for (j in 1 until way.size) {
        val x1 = if (way[j - 1] == 0) xs else x[way[j - 1] - 1]
        val y1 = if (way[j - 1] == 0) ys else y[way[j - 1] - 1]
        val x2 = if (way[j] == 0) xs else x[way[j] - 1]
        val y2 = if (way[j] == 0) ys else y[way[j] - 1]
        answer += ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))
    }
    println(answer)
    println(way.joinToString(" "))
}