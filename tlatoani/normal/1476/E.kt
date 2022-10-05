import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.system.exitProcess

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, k) = jin.readLine().split(" ").map { it.toInt() }
    val patterns = mutableMapOf<String, Int>()
    for (j in 1..n) {
        patterns[jin.readLine()] = j
    }
    val adj = Array(n + 1) { mutableListOf<Int>() }
    val strings = Array(m) {
        val line = jin.readLine().split(" ")
        Pair(line[0], line[1].toInt())
    }
    for ((string, toMatch) in strings) {
        var found = false
        for (mask in 0 until (1 shl k)) {
            var pattern = ""
            for (d in 0 until k) {
                pattern += if ((mask shr d) and 1 == 0) '_' else string[d]
            }
            val j = patterns[pattern]
            if (j != null) {
                if (j == toMatch) {
                    found = true
                } else {
                    adj[toMatch].add(j)
                }
            }
        }
        if (!found) {
            println("NO")
            return
        }
    }
    val order = mutableListOf<Int>()
    val seen = BooleanArray(n + 1)
    val rn = BooleanArray(n + 1)
    fun dfs(a: Int) {
        if (seen[a]) {
            if (rn[a]) {
                println("NO")
                exitProcess(0)
            }
        } else {
            seen[a] = true
            rn[a] = true
            for (b in adj[a]) {
                dfs(b)
            }
            order.add(a)
            rn[a] = false
        }
    }
    for (a in 1..n) {
        dfs(a)
    }
    println("YES")
    println(order.reversed().joinToString(" "))
}