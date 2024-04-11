import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val treeMap = TreeMap<Long, Long>()
        treeMap[0L] = 0
        var maximo = 0L
        var sum = 0L
        var tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            sum += tokenizer.nextToken().toLong()
            if (sum > maximo) {
                maximo = sum
                treeMap[sum] = j.toLong()
            }
        }
        tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..m) {
            val x = tokenizer.nextToken().toLong()
            if (x > maximo && sum <= 0L) {
                out.append(-1)
            } else {
                val cycles = if (sum <= 0L) 0L else max(0L, (x - maximo + sum - 1L) / sum)
                out.append((cycles * n.toLong()) + treeMap.ceilingEntry(x - (cycles * sum)).value - 1L)
            }
            out.append(' ')
        }
        out.appendln()
    }
    print(out)
}