import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val tokenizer = StringTokenizer(jin.readLine())
        val p = IntArray(n) { tokenizer.nextToken().toInt() - 1 }
        val pinv = IntArray(n)
        for (j in 0 until n) {
            pinv[p[j]] = j
        }
        val left = IntArray(n) { it - 1 }
        val right = IntArray(n) { it + 1 }
        val freq = TreeMap<Int, Int>()
        freq[1] = n
        var answer = true
        for (j in pinv) {
            while (freq.lastEntry().value == 0) {
                freq.remove(freq.lastKey())
            }
            if (j - left[j] < freq.lastKey()) {
                answer = false
                break
            }
            freq[j - left[j]] = freq[j - left[j]]!! - 1
            if (right[j] != n) {
                freq[right[j] - j] = freq[right[j] - j]!! - 1
            }
            if (left[j] != -1) {
                right[left[j]] = right[j]
            }
            if (right[j] != n) {
                left[right[j]] = left[j]
            }
            if (right[j] != n) {
                freq[right[j] - left[j]] = (freq[right[j] - left[j]] ?: 0) + 1
            }
        }
        out.appendln(if (answer) "Yes" else "No")
    }
    print(out)
}