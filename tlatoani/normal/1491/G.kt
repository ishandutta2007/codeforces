import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val p = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    val q = IntArray(n + 1)
    for (j in 1..n) {
        q[p[j]] = j
    }
    val seen = BooleanArray(n + 1)
    val cycles = mutableListOf<List<Int>>()
    for (r in 1..n) {
        if (!seen[r]) {
            seen[r] = true
            val cycle = mutableListOf(r)
            var j = p[r]
            while (j != r) {
                seen[j] = true
                cycle.add(j)
                j = p[j]
            }
            cycles.add(cycle)
        }
    }
    val out = StringBuilder()
    fun swap(a: Int, b: Int) {
        val c = q[a]
        val d = q[b]
        out.appendln("$c $d")
        q[a] = d
        q[b] = c
    }
    if (cycles.size == 1) {
        if (n == 3) {
            val (a, b, c) = cycles[0]
            swap(a, b)
            swap(a, c)
            swap(a, b)
            swap(a, c)
        } else {
            val (a, b, c, d) = cycles[0]
            swap(a, c)
            swap(a, d)
            val newCycle = listOf(c, a, b, d) + cycles[0].subList(4, n)
            for (j in 1..2) {
                swap(newCycle[j - 1], newCycle[j])
            }
            for (j in 4..newCycle.lastIndex) {
                swap(newCycle[j - 1], newCycle[j])
            }
            swap(newCycle[2], newCycle.last())
        }
    } else {
        var x = 0
        while (x < cycles.size) {
            val y = if (x + 3 == cycles.size) cycles.size else (x + 2)
            for (j in y - 1 downTo x + 1) {
                swap(cycles[j][0], cycles[if (j == y - 1) x else (j + 1)][0])
            }
            for (j in 1..cycles[x].lastIndex) {
                swap(cycles[x][j - 1], cycles[x][j])
            }
            val rest = mutableListOf<Int>()
            for (j in x + 1 until y) {
                rest.addAll(cycles[j])
            }
            for (j in 1..rest.lastIndex) {
                swap(rest[j - 1], rest[j])
            }
            swap(cycles[x].last(), rest.last())
            x = y
        }
    }
    println(out.count { it == '\n' })
    print(out)
}