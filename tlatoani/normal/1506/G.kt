import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        val next = Array(s.length + 1) { Array(26) { s.length } }
        for (k in s.lastIndex downTo 0) {
            next[k + 1].copyInto(next[k])
            next[k][s[k] - 'a'] = k
        }
        val lastIndexes = IntArray(26) { s.lastIndexOf('a' + it) }
        val amtDistinct = s.toSet().size
        val used = BooleanArray(26)
        var k = -1
        while (k < s.lastIndex) {
            var found = false
            for (j in 25 downTo 0) {
                if (!used[j] && next[k + 1][j] != s.length) {
                    var covers = 0
                    for (j2 in 0..25) {
                        if (used[j2] || lastIndexes[j2] >= next[k + 1][j]) {
                            covers++
                        }
                    }
                    if (covers == amtDistinct) {
                        found = true
                        k = next[k + 1][j]
                        break
                    }
                }
            }
            if (!found) {
                break
            }
            out.append(s[k])
            used[s[k] - 'a'] = true
        }
        out.appendln()
    }
    print(out)
}