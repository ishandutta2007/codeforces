import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val table = Array(2) { jin.readLine().split(" ").map { it.toInt() } }
        val amt = IntArray(n + 1)
        val sum = IntArray(n + 1)
        for (j in 0 until n) {
            for (b in 0..1) {
                amt[table[b][j]]++
                sum[table[b][j]] += j
            }
        }
        if ((1..n).any { amt[it] != 2 }) {
            out.appendln(-1)
            continue
        }
        val answer = mutableListOf<Int>()
        val seen = BooleanArray(n)
        for (r in 0 until n) {
            if (!seen[r]) {
                seen[r] = true
                val left = mutableListOf<Int>()
                val right = mutableListOf<Int>()
                left.add(r + 1)
                var total = 1
                var a = r
                var b = sum[table[1][r]] - r
                var inv = false
                while (b != r) {
                    seen[b] = true
                    total++
                    if (table[0][a] == table[0][b] || table[1][a] == table[1][b]) {
                        inv = !inv
                    }
                    if (inv) {
                        right.add(b + 1)
                    } else {
                        left.add(b + 1)
                    }
                    var x = table[0][b] + table[1][b]
                    if (table[0][a] == table[0][b] || table[0][a] == table[1][b]) {
                        x -= table[0][a]
                    } else {
                        x -= table[1][a]
                    }
                    a = b
                    b = sum[x] - b
                }
                if (left.size <= right.size) {
                    answer.addAll(left)
                } else {
                    answer.addAll(right)
                }
            }
        }
        out.appendln(answer.size)
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}