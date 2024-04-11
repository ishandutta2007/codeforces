import java.lang.StringBuilder
import java.util.*

fun main() {
    val out = StringBuilder()
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var tokenizer = StringTokenizer(readLine()!!)
        val a = Array(n) { tokenizer.nextToken().toInt() }
        a.sort()
        tokenizer = StringTokenizer(readLine()!!)
        val b = Array(n) { tokenizer.nextToken().toInt() }
        b.sort()
        for (j in 0 until n) {
            out.append(a[j]).append(' ')
        }
        out.appendln()
        for (j in 0 until n) {
            out.append(b[j]).append(' ')
        }
        out.appendln()
    }
    print(out)
}