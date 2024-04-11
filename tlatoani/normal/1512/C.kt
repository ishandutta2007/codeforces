import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        var (a, b) = jin.readLine().split(" ").map { it.toInt() }
        val s = jin.readLine().toCharArray()
        for (j in s.indices) {
            if (s[j] == '?') {
                if (s[s.lastIndex - j] != '?') {
                    s[j] = s[s.lastIndex - j]
                }
            }
        }
        for (j in s.indices) {
            when (s[j]) {
                '0' -> a--
                '1' -> b--
            }
            if (s[j] != s[s.lastIndex - j]) {
                out.appendln(-1)
                continue@cases
            }
        }
        if (a < 0 || b < 0) {
            out.appendln(-1)
            continue@cases
        }
        if (a % 2 == 1) {
            if (s.size % 2 == 1 && s[s.size / 2] == '?') {
                s[s.size / 2] = '0'
                a--
            } else {
                out.appendln(-1)
                continue@cases
            }
        }
        if (b % 2 == 1) {
            if (s.size % 2 == 1 && s[s.size / 2] == '?') {
                s[s.size / 2] = '1'
                b--
            } else {
                out.appendln(-1)
                continue@cases
            }
        }
        for (j in s.indices) {
            if (s[j] == '?') {
                if (a > 0) {
                    s[j] = '0'
                    s[s.lastIndex - j] = '0'
                    a -= 2
                } else {
                    s[j] = '1'
                    s[s.lastIndex - j] = '1'
                    b -= 2
                }
            }
        }
        out.appendln(s)
    }
    print(out)
}