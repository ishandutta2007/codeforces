const val M = 998244353

class Mint(val value: Int = 0) {
    operator fun plus(other: Mint): Mint {
        var sum = value + other.value
        if (sum >= M) {
            sum -= M
        }
        return Mint(sum)
    }

    operator fun minus(other: Mint): Mint {
        var diff = value - other.value
        if (diff < 0) {
            diff += M
        }
        return Mint(diff)
    }

    operator fun times(other: Mint) = Mint((value.toLong() * other.value.toLong() % M).toInt())

    override fun toString(): String = value.toString()

    fun pow(x: Int = M - 2): Mint {
        var ans = Mint(1)
        var a = this
        var b = x

        while (b > 0) {
            if (b % 2 == 1) {
                ans *= a
            }
            a *= a
            b /= 2
        }

        return ans
    }
}

val ZERO = Mint(0)
val ONE = Mint(1)

fun main() {
    val (n, a, b) = readLine()!!.split(" ").map { it.toInt() }

    var xCoords = mutableListOf(0, a)
    var yCoords = mutableListOf(0, b)

    val probPos = Array(a + b + 1) { ZERO }
    val probNeg = Array(a + b + 1) { ZERO }

    for (i in 0 until n) {
        val (x, y, p) = readLine()!!.split(" ").map { it.toInt() }
        val prob = Mint(p) * Mint(1000000).pow()

        xCoords.add(x)
        yCoords.add(y)

        probPos[x - y + b] = ONE - (ONE - prob) * (ONE - probPos[x - y + b])
        probNeg[x + y] = ONE - (ONE - prob) * (ONE - probNeg[x + y])
    }

    xCoords = xCoords.sorted().distinct().toMutableList()
    yCoords = yCoords.sorted().distinct().toMutableList()

    var ans = ZERO

    for (i in 1 until xCoords.size) {
        for (j in 1 until yCoords.size) {
            val (x1, x2) = listOf(xCoords[i - 1], xCoords[i])
            val (y1, y2) = listOf(yCoords[j - 1], yCoords[j])

            ans += ONE

            for (k in x1 + y1 + 1 until x2 + y2) {
                ans += probNeg[k]
            }

            for (k in x1 - y2 + 1 until x2 - y1) {
                ans += probPos[k + b]
            }

            for (k1 in x1 + y1 + 1 until x2 + y2) {
                for (k2 in x1 - y2 + 1 until x2 - y1) {
                    if (k1 + k2 in 2 * x1 + 1 until 2 * x2 && k1 - k2 in 2 * y1 + 1 until 2 * y2) {
                        ans += probNeg[k1] * probPos[k2 + b]
                    }
                }
            }
        }
    }

    println(ans)
}