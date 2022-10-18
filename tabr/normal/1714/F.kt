import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var (n, d12, d23, d31) = ints()
        var ans = ArrayList<Pair<Int, Int>>()
        var p = IntArray(n)
        for (i in 0..d12) {
            var e = d31 - i
            if (e < 0 || e + d12 - i != d23 || d12 + e + 1 > n) {
                continue
            }
            for (j in 1..d12) {
                ans.add(Pair(j - 1, j))
            }
            for (j in d12 + 1..d12 + e) {
                if (j == d12 + 1) {
                    ans.add(Pair(i, j))
                } else {
                    ans.add(Pair(j - 1, j))
                }
            }
            for (j in d12 + e + 1..n - 1) {
                ans.add(Pair(0, j))
            }
            var s = TreeSet<Int>()
            for (j in 0..n - 1) {
                s.add(j)
            }
            p[0] = 0
            p[1] = d12
            if (e == 0) {
                p[2] = i
            } else {
                p[2] = d12 + e
            }
            s.remove(p[0])
            s.remove(p[1])
            s.remove(p[2])
            for (j in 3..n - 1) {
                p[j] = s.first()
                s.remove(p[j])
            }
        }
        if (ans.isEmpty()) {
            cout("NO")
            continue
        }
        var q = IntArray(n)
        for (i in 0..n - 1) {
            q[p[i]] = i
        }
        cout("YES")
        for ((x, y) in ans) {
            cout("${q[x] + 1} ${q[y] + 1}")
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