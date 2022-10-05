import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val a = jin.readLine().split(" ").map { it.toInt() }.toIntArray()
        val ps = jin.readLine().split(" ").map { it.toInt() - 1 }.sorted()
        var j = 0
        var k = 0
        for (p in ps) {
            if (p > k) {
                a.sort(j, k + 1)
                j = p
            }
            k = p + 1
        }
        a.sort(j, k + 1)
        var answer = true
        for (j in 1 until n) {
            if (a[j - 1] > a[j]) {
                answer = false
                break
            }
        }
        println(if (answer) "YES" else "NO")
    }
}