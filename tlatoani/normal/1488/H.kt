import java.io.BufferedReader
import java.io.InputStreamReader

const val CHARACTERS = 4
const val MOD = 998244353L

fun main() {
    val transition = Array(2) { Array(2) { Array(CHARACTERS) { LongArray(CHARACTERS) } } }
    fun eval(b: Boolean) = if (b) 1L else 0L
    for (y in 0 until CHARACTERS) {
        for (x in 0 until CHARACTERS) {
            transition[0][1][y][x] = eval(x > y)
            transition[0][0][y][x] = eval(x >= y)
            transition[1][0][y][x] = eval(x < y)
            transition[1][1][y][x] = eval(x <= y)
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val segTree = SegmentTree(n - 1, transition[0][0])
    val constraints = (listOf(0) + jin.readLine().split(" ").map { it.toInt() } + listOf(0)).toIntArray()
    for (j in 1 until n) {
        segTree.update(j, transition[constraints[j]][constraints[j + 1]])
    }
    val out = StringBuilder()
    for (j in 1..q) {
        val k = jin.readLine().toInt()
        constraints[k] = 1 - constraints[k]
        if (k > 1) {
            segTree.update(k - 1, transition[constraints[k - 1]][constraints[k]])
        }
        segTree.update(k, transition[constraints[k]][constraints[k + 1]])
        out.appendln(segTree.query())
    }
    print(out)
}

fun multiply(a: Array<LongArray>, b: Array<LongArray>): Array<LongArray> {
    val res = Array(CHARACTERS) { LongArray(CHARACTERS) }
    for (j in 0 until CHARACTERS) {
        for (l in 0 until CHARACTERS) {
            for (k in 0 until CHARACTERS) {
                res[j][l] += a[j][k] * b[k][l]
            }
            res[j][l] %= MOD
        }
    }
    return res
}

class SegmentTree(val n: Int, val initialValue: Array<LongArray>) {
    val value = Array(300000) { initialValue }

    fun init(node: Int, segFrom: Int, segTo: Int) {
        if (segFrom < segTo) {
            val mid = (segFrom + segTo) / 2
            init(2 * node, segFrom, mid)
            init((2 * node) + 1, mid + 1, segTo)
            value[node] = multiply(value[2 * node], value[(2 * node) + 1])
        }
    }

    init {
        init(1, 1, n)
    }

    fun update(index: Int, delta: Array<LongArray>) = update(index, delta, 1, 1, n)

    fun update(index: Int, delta: Array<LongArray>, node: Int, segFrom: Int, segTo: Int) {
        if (segFrom == segTo) {
            value[node] = delta
        } else {
            val mid = (segFrom + segTo) / 2
            if (index <= mid) {
                update(index, delta, 2 * node, segFrom, mid)
            } else {
                update(index, delta, (2 * node) + 1, mid + 1, segTo)
            }
            value[node] = multiply(value[2 * node], value[(2 * node) + 1])
        }
    }

    fun query() = value[1].map { it.sum() % MOD }.sum() % MOD
}