import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var n = int()
    fun ask(a: Int, b: Int): Int {
        println("? ${a} ${b}")
        var t = int()
        return t
    }

    var x = ask(1, n)
    var hi = n
    var lo = 1
    while (hi - lo > 1) {
        var mid = (hi + lo) / 2
        var t = ask(1, mid)
        if (t == x) {
            hi = mid
        } else {
            lo = mid
        }
    }
    val y = hi
    lo = 1
    while (hi - lo > 1) {
        var mid = (hi + lo) / 2
        var t = ask(mid, y)
        if (t == x) {
            lo = mid
        } else {
            hi = mid
        }
    }
    var t = ask(lo, y)
    println("! ${t xor lo xor y}")
}

fun string() = input.readLine()
fun int() = string().toInt()
fun long() = string().toLong()
fun strings() = ArrayList(string().split(" "))
fun ints() = ArrayList(string().split(" ").map { it.toInt() })
fun longs() = ArrayList(string().split(" ").map { it.toLong() })
fun cout(s: String) = output.appendLine(s)
fun <T> cout(s: T) = output.appendLine(s.toString())
fun cout(s: IntArray) = output.appendLine(s.joinToString(" "))
fun cout(s: LongArray) = output.appendLine(s.joinToString(" "))
fun <T> cout(s: Array<T>) = output.appendLine(s.joinToString(" "))
fun <T> cout(s: Iterable<T>) = output.appendLine(s.joinToString(" "))
fun assert(x: Boolean) {
    if (!x) throw AssertionError()
}