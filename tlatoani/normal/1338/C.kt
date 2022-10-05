import java.io.BufferedReader
import java.io.InputStreamReader

val combos = arrayOf(
        arrayOf(0L, 0L, 0L),
        arrayOf(1L, 2L, 3L),
        arrayOf(2L, 3L, 1L),
        arrayOf(3L, 1L, 2L)
)

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toLong()
        var n3 = ((n - 1L) / 3L)
        var k = 0
        while (n3 >= (1L shl k)) {
            n3 -= 1L shl k
            k += 2
        }
        var m = ((n - 1L) % 3L).toInt()
        var res = 0L
        var e = 0
        while (e < k) {
            res += combos[(n3 and 3L).toInt()][m] shl e
            n3 /= 4L
            e += 2
        }
        res += combos[1][m] shl k
        out.appendln(res)
    }
    print(out)
}