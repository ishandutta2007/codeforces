import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var (n, m, k) = jin.readLine().split(" ").map { it.toInt() }
    var dir = jin.readLine().last() == 'l'
    val state = jin.readLine()
    var prev = mutableListOf(m)
    var answer = 0
    for (chara in state) {
        answer++
        val prevK = k
        if (k == 1) {
            dir = true
        } else if (k == n) {
            dir = false
        }
        if (dir) {
            k++
        } else {
            k--
        }
        val next = mutableSetOf<Int>()
        if (chara == '0') {
            for (x in prev) {
                if (x != k) {
                    next.add(x)
                }
                if (x != 1 && x - 1 != prevK && x - 1 != k) {
                    next.add(x - 1)
                }
                if (x != n && x + 1 != prevK && x + 1 != k) {
                    next.add(x + 1)
                }
            }
        } else {
            next.addAll(1..n)
            next.remove(k)
        }
        if (next.isEmpty()) {
            println("Controller")
            println(answer)
            return
        }
        prev = next.toMutableList()
    }
    println("Stowaway")
}