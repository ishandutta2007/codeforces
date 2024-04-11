import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m0, m1) = jin.readLine().split(" ").map { it.toInt() }
    val union = Array(2) { Array(n + 1) { it } }
    fun find(which: Int, u: Int): Int {
        if (union[which][union[which][u]] != union[which][u]) {
            union[which][u] = find(which, union[which][u])
        }
        return union[which][u]
    }
    val components = Array(2) { TreeSet<Int>() }
    components.forEach { it.addAll(1..n) }
    fun merge(which: Int, a: Int, b: Int) {
        val u = find(which, a)
        val v = find(which, b)
        components[which].remove(u)
        union[which][u] = v
    }
    val ms = listOf(m0, m1)
    for (which in 0..1) {
        repeat(ms[which]) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            merge(which, a, b)
        }
    }
    val out = StringBuilder()
    fun addEdge(a: Int, b: Int) {
        out.appendln("$a $b")
        merge(0, a, b)
        merge(1, a, b)
    }
    while (components.all { it.size > 1 }) {
        val u = components[0].first()
        val v = components[0].last()
        if (find(1, u) == find(1, v)) {
            val x = components[1].first()
            val y = components[1].last()
            if (find(1, u) == x) {
                if (find(0, y) == u) {
                    addEdge(v, y)
                } else {
                    addEdge(u, y)
                }
            } else {
                if (find(0, x) == u) {
                    addEdge(v, x)
                } else {
                    addEdge(u, x)
                }
            }
        } else {
            addEdge(u, v)
        }
    }
    println(out.count { it == '\n' })
    print(out)
}