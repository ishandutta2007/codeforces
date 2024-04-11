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
        var (h, w, k) = ints()
        var a = h * w / 2
        k = a - k
        if (h % 2 == 1) {
            if (k % 2 == (a - w / 2) % 2 && k <= a - w / 2) {
                cout("YES")
                var s = Array<CharArray>(h) { CharArray(w) }
                k /= 2
                for (j in 0..w - 1 step 2) {
                    var c = ('x' + (j / 2 % 2)).toChar()
                    s[h - 1][j] = c
                    s[h - 1][j + 1] = c
                }
                for (i in 0..h - 3 step 2) {
                    var c = ('a' + i / 2 % 2 * 2).toChar()
                    for (j in 0..w - 1 step 2) {
                        if (k-- > 0) {
                            s[i][j] = c
                            s[i + 1][j] = c
                            c++
                            s[i][j + 1] = c
                            s[i + 1][j + 1] = c
                        } else {
                            s[i][j] = c
                            s[i][j + 1] = c
                            c++
                            s[i + 1][j] = c
                            s[i + 1][j + 1] = c
                        }
                        c++
                        if (c == 'e') {
                            c = 'a'
                        }
                    }
                }
                for (i in s) {
                    cout(i.joinToString(""))
                }
            } else {
                cout("NO")
            }
        } else if (w % 2 == 1) {
            if (k % 2 == h / 2 % 2 && k >= h / 2) {
                cout("YES")
                var s = Array<CharArray>(h) { CharArray(w) }
                k -= h / 2
                k /= 2
                for (i in 0..h - 1 step 2) {
                    var c = ('x' + (i / 2 % 2)).toChar()
                    s[i][w - 1] = c
                    s[i + 1][w - 1] = c
                }
                for (i in 0..h - 1 step 2) {
                    var c = ('a' + i / 2 % 2 * 2).toChar()
                    for (j in 0..w - 3 step 2) {
                        if (k-- > 0) {
                            s[i][j] = c
                            s[i + 1][j] = c
                            c++
                            s[i][j + 1] = c
                            s[i + 1][j + 1] = c
                        } else {
                            s[i][j] = c
                            s[i][j + 1] = c
                            c++
                            s[i + 1][j] = c
                            s[i + 1][j + 1] = c
                        }
                        c++
                        if (c == 'e') {
                            c = 'a'
                        }
                    }
                }
                for (i in s) {
                    cout(i.joinToString(""))
                }
            } else {
                cout("NO")
            }
        } else {
            if (k % 2 == 0) {
                cout("YES")
                var s = Array<CharArray>(h) { CharArray(w) }
                k /= 2
                for (i in 0..h - 1 step 2) {
                    var c = ('a' + i / 2 % 2 * 2).toChar()
                    for (j in 0..w - 1 step 2) {
                        if (k-- > 0) {
                            s[i][j] = c
                            s[i + 1][j] = c
                            c++
                            s[i][j + 1] = c
                            s[i + 1][j + 1] = c
                        } else {
                            s[i][j] = c
                            s[i][j + 1] = c
                            c++
                            s[i + 1][j] = c
                            s[i + 1][j + 1] = c
                        }
                        c++
                        if (c == 'e') {
                            c = 'a'
                        }
                    }
                }
                for (i in s) {
                    cout(i.joinToString(""))
                }
            } else {
                cout("NO")
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