const val MINUS = '-'.toInt()
const val ZERO = '0'.toInt()
const val NINE = '9'.toInt()
val DIGITS = ZERO..NINE

fun readInt(): Int {
    var digit = System.`in`.read()
    val negative = digit == MINUS
    if (negative) {
        digit = System.`in`.read()
    }
    var res = 0
    while (digit in DIGITS) {
        res *= 10
        res += digit - ZERO
        digit = System.`in`.read()
    }
    if (res == 0) {
        return readInt()
    }
    return if (negative) -res else res
}

fun main() {
    val n = readInt()
    val q = readInt()
    val bit = BinaryIndexTree(1048576)
    for (j in 1..n) {
        val a = readInt()
        bit.update(a, 1)
    }
    for (j in 1..q) {
        val k = readInt()
        if (k > 0) {
            bit.update(k, 1)
        } else {
            bit.update(bit.statistic(-k), -1)
        }
    }
    println(bit.statistic(1) % 1048576)
}

class BinaryIndexTree(treeTo: Int) {
    val value = IntArray(treeTo + 1)

    fun update(index: Int, delta: Int) {
        var j = index
        while (j < value.size) {
            value[j] += delta
            j += j and -j
        }
    }

    fun statistic(k: Int): Int {
        var curr = 0
        var res = 0
        for (e in 19 downTo 0) {
            if (curr + value[res + (1 shl e)] < k) {
                res += 1 shl e
                curr += value[res]
            }
        }
        return res + 1
    }
}