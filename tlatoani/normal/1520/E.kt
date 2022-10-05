import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val out = StringBuilder()
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val s = jin.readLine()
        val ds = LongArray(n)
        var sheep = 0
        var curr = 0L
        for ((j, chara) in s.withIndex()) {
            if (chara == '*') {
                curr += (j - sheep).toLong()
                ds[0]--
                ds[j - sheep] += 2L
                sheep++
            }
        }
        var answer = curr
        var currD = ds[0]
        for (j in 1 until n) {
            curr += currD
            currD += ds[j]
            answer = min(answer, curr)
        }
        out.appendln(answer)
    }
    print(out)
}