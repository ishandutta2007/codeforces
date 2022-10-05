import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val freq = IntArray(n + 1)
        val choices = mutableListOf<Choice>()
        val answer = IntArray(m)
        for (j in 0 until m) {
            val tokenizer = StringTokenizer(jin.readLine())
            if (tokenizer.nextToken().toInt() == 1) {
                answer[j] = tokenizer.nextToken().toInt()
                freq[answer[j]]++
            } else {
                choices.add(Choice(j, tokenizer.nextToken().toInt(), tokenizer.nextToken().toInt()))
            }
        }
        if (freq.max()!! > (m + 1) / 2) {
            out.appendln("NO")
        } else {
            out.appendln("YES")
            for ((j, f, a) in choices) {
                if (freq[f] > freq[a]) {
                    answer[j] = a
                    freq[a]++
                } else {
                    answer[j] = f
                    freq[f]++
                }
            }
            out.appendln(answer.joinToString(" "))
        }
    }
    print(out)
}

data class Choice(val day: Int, val friend: Int, val amigo: Int)