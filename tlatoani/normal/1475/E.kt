import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 1000000007L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val choose = Array(1001) { LongArray(1001) }
    for (a in 0..1000) {
        choose[a][0] = 1L
        for (b in 1..a) {
            choose[a][b] = (choose[a - 1][b] + choose[a - 1][b - 1]) % MOD
        }
    }
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val bloggers = listOf(0) + jin.readLine().split(" ").map { it.toInt() }.sortedDescending()
        val prefix = bloggers.count { it > bloggers[k] }
        val space = bloggers.count { it == bloggers[k] }
        out.appendln(choose[space][k - prefix])
    }
    print(out)
}