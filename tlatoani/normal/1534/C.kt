import java.util.*

const val MOD = 1000000007L

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tokenizer1 = StringTokenizer(readLine()!!)
        val tokenizer2 = StringTokenizer(readLine()!!)
        val f = IntArray(n + 1)
        for (j in 1..n) {
            f[tokenizer1.nextToken().toInt()] = tokenizer2.nextToken().toInt()
        }
        val seen = BooleanArray(n + 1)
        var answer = 1L
        for (r in 1..n) {
            if (!seen[r]) {
                if (f[r] == r) {
                    answer = 0L
                } else {
                    var k = r
                    do {
                        seen[k] = true
                        k = f[k]
                    } while (k != r)
                    answer *= 2L
                    answer %= MOD
                }
            }
        }
        println(answer)
    }
}