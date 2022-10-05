import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val freq = IntArray(26)
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        for (chara in jin.readLine()) {
            freq[chara - 'a']++
        }
        for (chara in jin.readLine()) {
            freq[chara - 'a']--
        }
        for (j in 1..25) {
            freq[j] += freq[j - 1]
        }
        out.appendln(if (freq.all { it >= 0 && it % k == 0 }) "yEs" else "nO")
    }
    print(out)
}