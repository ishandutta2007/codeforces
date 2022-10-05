import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, k) = jin.readLine().split(" ").map { it.toInt() }
    val gobs = jin.readLine().split(" ").map { it.toInt() }.toSet()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(b)
        adj[b].add(a)
    }
    val nations = mutableListOf<Long>()
    var rem = 0L
    val seen = BooleanArray(n + 1)
    for (r in 1..n) {
        if (!seen[r]) {
            var total = 0
            var isGob = false
            fun recur(a: Int) {
                if (!seen[a]) {
                    total++
                    seen[a] = true
                    if (a in gobs) {
                        isGob = true
                    }
                    for (b in adj[a]) {
                        recur(b)
                    }
                }
            }
            recur(r)
            if (isGob) {
                nations.add(total.toLong())
            } else {
                rem += total.toLong()
            }
        }
    }
    nations.sortDescending()
    nations[0] = nations[0] + rem
    var answer = -m.toLong()
    for (nation in nations) {
        answer += (nation * (nation - 1L)) / 2L
    }
    println(answer)
}