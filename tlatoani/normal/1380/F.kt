import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val initial = " " + jin.readLine()
    val segTree = StrangeSegmentTree(initial)
    val out = StringBuilder()
    for (j in 1..m) {
        val (k, d) = jin.readLine().split(" ").map { it.toInt() }
        segTree.update(k, d)
        out.appendln(segTree.query())
    }
    print(out)
}

data class Ways(val first: Long, val last: Boolean, val amt00: Long, val amt01: Long, val amt10: Long, val amt11: Long)

inline fun require(cond: Boolean, amt: Long) = if (cond) amt else 0L

fun combine(left: Ways, right: Ways) = Ways(
        left.first,
        right.last,
        ((left.amt00 * right.amt00) + require(left.last, (right.first * ((left.amt01 * right.amt10) % MOD)))) % MOD,
        ((left.amt00 * right.amt01) + require(left.last, (right.first * ((left.amt01 * right.amt11) % MOD)))) % MOD,
        ((left.amt10 * right.amt00) + require(left.last, (right.first * ((left.amt11 * right.amt10) % MOD)))) % MOD,
        ((left.amt10 * right.amt01) + require(left.last, (right.first * ((left.amt11 * right.amt11) % MOD)))) % MOD
)

fun single(digit: Long) = Ways(
        9L - digit,
        digit == 1L,
        digit + 1L,
        1L,
        1L,
        0L
)

val DUMMY = Ways(0L, false, 0L, 0L, 0L, 0L)

class StrangeSegmentTree(val initial: String) {
    val n = initial.length - 1
    val ws = Array(1 shl 20) { DUMMY }

    init {
        init(1, 1, n)
    }

    fun init(node: Int, segFrom: Int, segTo: Int) {
        if (segFrom == segTo) {
            ws[node] = single((initial[segFrom] - '0').toLong())
        } else {
            val mid = (segFrom + segTo) / 2
            init(2 * node, segFrom, mid)
            init((2 * node) + 1, mid + 1, segTo)
            ws[node] = combine(ws[2 * node], ws[(2 * node) + 1])
        }
    }

    fun update(j: Int, digit: Int) = update(j, digit.toLong(), 1, 1, n)

    fun update(j: Int, digit: Long, node: Int, segFrom: Int, segTo: Int) {
        if (segFrom == segTo) {
            ws[node] = single(digit)
        } else {
            val mid = (segFrom + segTo) / 2
            if (j <= mid) {
                update(j, digit, 2 * node, segFrom, mid)
            } else {
                update(j, digit, (2 * node) + 1, mid + 1, segTo)
            }
            ws[node] = combine(ws[2 * node], ws[(2 * node) + 1])
        }
    }

    fun query() = ws[1].amt00
}