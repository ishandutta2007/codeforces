import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = jin.readLine().split(" ").map { it.toInt() }
    val both = mutableListOf<Int>()
    val alice = mutableListOf<Int>()
    val bob = mutableListOf<Int>()
    for (j in 1..n) {
        val (t, a, b) = jin.readLine().split(" ").map { it.toInt() }
        if (a == 1) {
            if (b == 1) {
                both.add(t)
            } else {
                alice.add(t)
            }
        } else {
            if (b == 1) {
                bob.add(t)
            }
        }
    }
    val overall = both.toMutableList()
    alice.sort()
    bob.sort()
    for (j in 0 until min(alice.size, bob.size)) {
        overall.add(alice[j] + bob[j])
    }
    overall.sort()
    if (overall.size < k) {
        println(-1)
    } else {
        println(overall.subList(0, k).sum())
    }
}