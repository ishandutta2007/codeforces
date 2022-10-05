import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        var k = line[1].toLong()
        val s = jin.readLine().toCharArray()
        val zeroes = TreeSet<Int>()
        for (j in 0 until n) {
            if (s[j] == '0') {
                zeroes.add(j)
            }
        }
        for (j in 0 until n) {
            if (s[j] == '1') {
                val j2 = zeroes.higher(j)
                if (j2 != null && j2 - j <= k) {
                    k -= (j2 - j).toLong()
                    s[j] = '0'
                    s[j2] = '1'
                    zeroes.remove(j2)
                }
            }
        }
        out.appendln(s)
    }
    print(out)
}