import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val tokenizer = StringTokenizer(jin.readLine())
        val array = Array(n) { tokenizer.nextToken().toInt() }
        array.sort()
        val answer = mutableListOf<Int>()
        for (j in 0 until n / 2) {
            answer.add(array[j])
            answer.add(array[n - j - 1])
        }
        if (n % 2 == 1) {
            answer.add(array[n / 2])
        }
        out.appendln(answer.reversed().joinToString(" "))
    }
    print(out)
}