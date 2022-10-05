import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        println(if ((1L..6L).contains((jin.nextLong() - 14L) % 14L)) "YES" else "NO")
    }
}