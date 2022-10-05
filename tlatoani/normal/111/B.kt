import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val factors = Array(100001) { mutableListOf<Int>() }
    for (f in 1..100000) {
        var k = f
        while (k <= 100000) {
            factors[k].add(f)
            k += f
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    val n = jin.readLine().toInt()
    val last = IntArray(100001)
    for (j in 1..n) {
        val (x, y) = jin.readLine().split(" ").map { it.toInt() }
        var res = 0
        for (f in factors[x]) {
            if (last[f] < j - y) {
                res++
            }
            last[f] = j
        }
        out.appendln(res)
    }
    print(out)
}