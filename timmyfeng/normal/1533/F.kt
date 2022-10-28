import kotlin.math.*
import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val s = reader.readLine()
    val n = s.length

    val whereZero = IntArray(2 * n + 1) { n }
    val whereOne = IntArray(2 * n + 1) { n }
    val countZero = IntArray(n + 1) { 0 }
    val countOne = IntArray(n + 1) { 0 }

    for (i in 0 until n) {
        if (s[i] == '0') {
            countZero[i + 1] = countZero[i] + 1
            countOne[i + 1] = countOne[i]
            whereZero[countZero[i]] = i
        } else {
            countOne[i + 1] = countOne[i] + 1
            countZero[i + 1] = countZero[i]
            whereOne[countOne[i]] = i
        }
    }

    for (i in 1..n) {
        var j = 0
        var ans = 0
        while (j < n) {
            j = max(whereZero[countZero[j] + i], whereOne[countOne[j] + i])
            ++ans
        }
        writer.print("$ans ")
    }
    writer.println()

    writer.close()
}