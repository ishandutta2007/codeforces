import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        val m = jin.readLine().toInt()
        val b = jin.readLine().split(" ").map { it.toInt() }.toIntArray()
        val freq = IntArray(26) { letter -> s.count { it == ('a' + letter) }}
        val answer = CharArray(m)
        val seen = BooleanArray(m)
        for (letter in 'z' downTo 'a') {
            val ixs = mutableListOf<Int>()
            for (j in 0 until m) {
                if (b[j] == 0 && !seen[j]) {
                    ixs.add(j)
                }
            }
            if (ixs.size <= freq[letter - 'a']) {
                for (j in ixs) {
                    seen[j] = true
                    answer[j] = letter
                }
                for (j in ixs) {
                    for (k in 0 until m) {
                        if (!seen[k]) {
                            b[k] -= abs(j - k)
                        }
                    }
                }
            }
        }
        out.appendln(answer)
    }
    print(out)
}