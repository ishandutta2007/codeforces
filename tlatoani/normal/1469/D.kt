import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        fun test(z: Int): Int {
            var amt = 0
            var x = n
            var y = z
            while (max(x, y) != 2 || min(x, y) != 1) {
                if (min(x, y) == 1) {
                    return Int.MAX_VALUE
                }
                if (x > y) {
                    x = (x + y - 1) / y
                } else {
                    y = (y + x - 1) / x
                }
                amt++
            }
            return amt
        }
        val z = (1 until n).minBy { test(it) }!!
        var amt = n - 3
        val operations = StringBuilder()
        for (j in 2 until n) {
            if (j != z) {
                operations.appendln("$j ${j + 1}")
            }
        }
        var x = n
        var y = z
        while (min(x, y) != 1) {
            if (x > y) {
                operations.appendln("$n $z")
                x = (x + y - 1) / y
            } else {
                operations.appendln("$z $n")
                y = (y + x - 1) / x
            }
            amt++
        }
        out.appendln(amt)
        out.append(operations)
    }
    print(out)
}