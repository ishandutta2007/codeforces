import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val places = jin.readLine().split(" ").map { it.toInt() }.toIntArray()
    val towers = Array(m + 1) { mutableListOf<Int>() }
    val union = IntArray(m + 1) { it }
    for (k in 0 until n) {
        towers[places[k]].add(k)
    }
    fun getUnion(u: Int): Int {
        if (union[union[u]] != union[u]) {
            union[u] = getUnion(union[u])
        }
        return union[u]
    }
    var curr = (1 until n).count { places[it - 1] != places[it] }
    val out = StringBuilder()
    out.appendln(curr)
    for (j in 1 until m) {
        var (a, b) = jin.readLine().split(" ").map { it.toInt() }
        a = getUnion(a)
        b = getUnion(b)
        if (towers[a].size > towers[b].size) {
            val c = a
            a = b
            b = c
        }
        for (k in towers[a]) {
            if (k > 0 && getUnion(places[k - 1]) == b) {
                curr--
            }
            if (k < n - 1 && getUnion(places[k + 1]) == b) {
                curr--
            }
            towers[b].add(k)
        }
        union[a] = b
        out.appendln(curr)
    }
    print(out)
}