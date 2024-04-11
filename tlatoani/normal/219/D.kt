import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(2) { Array(n + 1) { mutableListOf<Int>() } }
    for (j in 2..n) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[0][a].add(b)
        adj[1][b].add(a)
    }
    val up1 = IntArray(n + 1)
    val seen = BooleanArray(n + 1)
    fun recur1(a: Int) {
        for (b in adj[0][a]) {
            if (!seen[b]) {
                seen[b] = true
                recur1(b)
                up1[a] += up1[b]
            }
        }
        for (b in adj[1][a]) {
            if (!seen[b]) {
                seen[b] = true
                up1[a]++
                recur1(b)
                up1[a] += up1[b]
            }
        }
    }
    seen[1] = true
    recur1(1)
    val up2 = IntArray(n + 1)
    fun recur2(a: Int) {
        for (b in adj[0][a]) {
            if (seen[b]) {
                seen[b] = false
                up2[b] = up1[a] - up1[b] + up2[a] + 1
                recur2(b)
            }
        }
        for (b in adj[1][a]) {
            if (seen[b]) {
                seen[b] = false
                up2[b] = up1[a] - up1[b] + up2[a] - 1
                recur2(b)
            }
        }
    }
    recur2(1)
    var answer = n
    var pos = mutableListOf<Int>()
    for (a in 1..n) {
        if (up1[a] + up2[a] < answer) {
            answer = up1[a] + up2[a]
            pos.clear()
            pos.add(a)
        } else if (up1[a] + up2[a] == answer) {
            pos.add(a)
        }
    }
    pos.sort()
    println(answer)
    println(pos.joinToString(" "))
}