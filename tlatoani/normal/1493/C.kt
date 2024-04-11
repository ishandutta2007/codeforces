import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val s = jin.readLine().map { it - 'a' }
        if (n % k == 0) {
            val freq = IntArray(26)
            var needed = 0
            for (letter in s) {
                if (freq[letter] % k == 0) {
                    needed += k
                }
                freq[letter]++
                needed--
            }
            if (needed == 0) {
                for (letter in s) {
                    out.append('a' + letter)
                }
                out.appendln()
            } else {
                for (j in n - 1 downTo 0) {
                    for (letter in s[j] + 1..25) {
                        freq[letter - 1]--
                        needed++
                        if (freq[letter - 1] % k == 0) {
                            needed -= k
                        }
                        if (freq[letter] % k == 0) {
                            needed += k
                        }
                        freq[letter]++
                        needed--
                        if (n - j - 1 >= needed) {
                            for (j2 in 0 until j) {
                                out.append('a' + s[j2])
                            }
                            out.append('a' + letter)
                            out.append("a".repeat((n - j - 1) - needed))
                            for (letter2 in 0..25) {
                                out.append(('a' + letter2).toString().repeat((k - (freq[letter2] % k)) % k))
                            }
                            out.appendln()
                            continue@cases
                        }
                    }
                    freq[25]--
                    needed++
                    if (freq[25] % k == 0) {
                        needed -= k
                    }
                }
            }
        } else {
            out.appendln(-1)
        }
    }
    print(out)
}