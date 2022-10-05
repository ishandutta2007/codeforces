import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val shifts = LongArray(61)
    val pow2 = LongArray(61) { 1L shl it }
    val out = BufferedWriter(OutputStreamWriter(System.`out`))
    for (j in 1..jin.readLine().toInt()) {
        var tokenizer = StringTokenizer(jin.readLine())
        when (tokenizer.nextToken().toInt()) {
            1 -> {
                var x = tokenizer.nextToken().toLong()
                val k = tokenizer.nextToken().toLong()
                var lg = 0
                while (x > 1L) {
                    x /= 2L
                    lg++
                }
                shifts[lg] -= k
                shifts[lg] %= pow2[lg]
            }
            2 -> {
                var x = tokenizer.nextToken().toLong()
                var k = tokenizer.nextToken().toLong()
                var lg = 0
                while (x > 1L) {
                    x /= 2L
                    lg++
                }
                k %= pow2[lg]
                for (e in lg..59) {
                    shifts[e] -= k * pow2[e - lg]
                    shifts[e] %= pow2[e]
                }
            }
            3 -> {
                val x = tokenizer.nextToken().toLong()
                var xt = x
                var lg = 0
                while (xt > 1L) {
                    xt /= 2L
                    lg++
                }
                var node = (((x - shifts[lg]) % pow2[lg]) + pow2[lg]) % pow2[lg]
                for (e in lg downTo 0) {
                    out.write((pow2[e] + ((((node + shifts[e]) % pow2[e]) + pow2[e]) % pow2[e])).toString())
                    out.write(" ")
                    node /= 2L
                }
                out.appendln()
            }
        }
    }
    out.flush()
}