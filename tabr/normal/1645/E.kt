import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, k) = ints()
    if (n < k) {
        println("NO")
        return
    }
    var cnt = IntArray(30)
    for (i in 0..29) {
        if ((n and (1 shl i)) != 0) {
            cnt[i]++
        }
    }
    if (cnt.sum() > k) {
        println("NO")
        return
    }
    var s = cnt.sum()
    while (s < k) {
        for (i in 29 downTo 1) {
            if (cnt[i] > 0) {
                cnt[i]--
                cnt[i - 1] += 2
                break
            }
        }
        s++
    }
    cout("YES")
    var ans = ArrayList<Int>()
    for (i in 0..29) {
        for (j in 0..cnt[i] - 1) {
            ans.add(1 shl i)
        }
    }
    cout(ans)
    print(output)
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