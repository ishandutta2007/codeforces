import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val s = Array(n) { jin.next() }
    val t = Array(m) { jin.next() }
    val q = jin.nextInt()
    for (c in 1..q) {
        val y = jin.nextInt() - 1
        println(s[y % n] + t[y % m])
    }
}