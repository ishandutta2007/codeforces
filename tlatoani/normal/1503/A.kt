import java.util.*

fun main() {
    val out = StringBuilder()
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        if (s.count { it == '0' } % 2 == 1 || s[0] == '0' || s.last() == '0') {
            out.appendln("nO")
        } else {
            out.appendln("yEs")
            var d = s.count { it == '1' } / 2
            var parity = true
            for (j in 0 until n) {
                if (s[j] == '0') {
                    out.append(if (parity) '(' else ')')
                    parity = !parity
                } else {
                    out.append(if (d > 0) '(' else ')')
                    d--
                }
            }
            out.appendln()
            d = s.count { it == '1' } / 2
            parity = true
            for (j in 0 until n) {
                if (s[j] == '0') {
                    out.append(if (parity) ')' else '(')
                    parity = !parity
                } else {
                    out.append(if (d > 0) '(' else ')')
                    d--
                }
            }
            out.appendln()
        }
    }
    print(out)
}