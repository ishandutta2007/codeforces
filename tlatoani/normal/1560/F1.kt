import kotlin.math.min

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val digits = n.toString().map { it - '0' }
        if (digits.size == 10 && k == 1) {
            out.appendln("1".repeat(10))
        } else if (digits.toSet().size <= k) {
            out.appendln(n)
        } else {
            var answer = 1111111111
            var currPrefix = 0
            var currPow = ("1" + "0".repeat(digits.size - 1)).toInt()
            var currRepeated = "1".repeat(digits.size - 1).toInt()
            val currSet = mutableSetOf<Int>()
            for (digit in digits) {
                for (a in digit + 1..9) {
                    for (b in 0..a) {
                        if (currSet.size + (if (a in currSet) 0 else 1) + (if (b in currSet || b == a) 0 else 1) <= k) {
                            answer = min(answer, currPrefix + (a * currPow) + (b * currRepeated))
                        }
                    }
                }
                currPrefix += currPow * digit
                currPow /= 10
                currRepeated /= 10
                currSet.add(digit)
            }
            out.appendln(answer)
        }
    }
    print(out)
}