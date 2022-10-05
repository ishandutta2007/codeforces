import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val answer = IntArray(n)
        val seen = BooleanArray(n + 1)
        var k = 0
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..2 * n) {
            val a = tokenizer.nextToken().toInt()
            if (!seen[a]) {
                answer[k] = a
                seen[a] = true
                k++
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}

/*

5
2
1 1 2 2
4
1 3 1 4 3 4 2 2
5
1 2 1 2 3 4 3 5 4 5
3
1 2 3 1 2 3
4
2 3 2 4 1 3 4 1

 */