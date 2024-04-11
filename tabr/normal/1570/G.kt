import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var k = 1 shl 7
    var a = IntArray(100)
    for (i in 0..99) {
        a[i] = i
    }
    print("? ")
    println(a.joinToString(" "))
    System.out.flush()
    var x = int()
    var ans = 0
    ans = x / k * k
    for (i in 0..99) {
        a[i] = (i + 1) * k
    }
    print("? ")
    println(a.joinToString(" "))
    System.out.flush()
    var y = int()
    ans += y % k
    print("! ")
    println(ans)
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