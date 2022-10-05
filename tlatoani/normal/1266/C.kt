import java.lang.StringBuilder
import java.util.*

fun main() {
    val tokenizer = StringTokenizer(readLine()!!)
    val r = tokenizer.nextToken().toInt()
    val c = tokenizer.nextToken().toInt()
    val out = StringBuilder()
    if (r == 1) {
        if (c == 1) {
            out.appendln(0)
        } else {
            out.appendln((2..c + 1).joinToString(" ", "", ""))
        }
    } else {
        if (c == 1) {
            out.appendln((2..r + 1).joinToString("\n", "", ""))
        } else {
            for (y in 1..r) {
                for (x in 1..c) {
                    out.append(y * (x + r)).append(' ')
                }
                out.appendln()
            }
        }
    }
    print(out)
}