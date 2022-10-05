import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val ay = jin.readLine().split(" ").map { it.toLong() }
    val out = StringBuilder()
    if (n == 1) {
        out.appendln("1 1")
        out.appendln(0)
        out.appendln("1 1")
        out.appendln(0)
        out.appendln("1 1")
        out.appendln(-ay[0])
    } else {
        out.appendln("1 $n")
        for (j in 1 until n) {
            out.append(-n.toLong() * ay[j - 1]).append(' ')
        }
        out.appendln(0)
        out.appendln("1 ${n - 1}")
        for (j in 1 until n) {
            out.append((n - 1).toLong() * ay[j - 1]).append(' ')
        }
        out.appendln()
        out.appendln("$n $n")
        out.appendln(-ay[n - 1])
    }
    print(out)
}