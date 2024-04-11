import java.io.BufferedWriter
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val jout = PrintWriter(BufferedWriter(OutputStreamWriter(System.`out`)))
    for (h in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val k = jin.nextInt()
        val sums = IntArray(3)
        jin.nextLine()
        val s = jin.nextLine()
        var res = 1 shl 24
        for (i in 0 until n) {
            sums[(333 - s[i].toInt() + i) % 3]--
            if (i < k) {
                for (j in 0..2) {
                    sums[j]++
                }
            } else {
                sums[(333 - s[i - k].toInt() + i - k) % 3]++
            }
            if (i >= k - 1) {
                for (j in 0..2) {
                    res = min(res, sums[j])
                }
            }
        }
        jout.println(res)
    }
    jout.flush()
}