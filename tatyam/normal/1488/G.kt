import kotlin.math.*
import java.util.*

val sc = Scanner(System.`in`)

fun main() {
    val n = sc.nextInt()
    val a = MutableList(n + 1) { 0 }
    for (i in 1 .. n) {
        for (j in i * 2 .. n step i) {
            a[j]++
            a[i]--
        }
    }
    a.removeAt(0)
    a.sortDescending()
    for (i in 0 until n - 1) a[i + 1] += a[i]
    println(a.joinToString(" "))
}