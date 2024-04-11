import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var n = int()
        var mp = mutableMapOf<String, Pair<String, Long>>()
        while (n-- > 0) {
            var s = strings()
            if (s[1] == ":=") {
                var c = 0L
                for (i in 0..s[2].length - 4) {
                    if ("haha" == s[2].substring(i, i + 4)) {
                        c++
                    }
                }
                mp[s[0]] = Pair(s[2], c)
            } else {
                var t = mp[s[2]]!!.first + mp[s[4]]!!.first
                var c = 0L
                var len = mp[s[2]]!!.first.length
                var l = maxOf(0, len - 3)
                for (i in l..l + 3) {
                    if (i < len && i + 4 <= t.length && "haha" == t.substring(i, i + 4)) {
                        c++
                    }
                }
                if (t.length >= 9) {
                    t = t.substring(0, 4) + "?" + t.substring(t.length - 4, t.length)
                }
                mp[s[0]] = Pair(t, mp[s[2]]!!.second + mp[s[4]]!!.second + c)
            }
            if (n == 0) {
                cout(mp[s[0]]!!.second)
            }
        }
    }
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