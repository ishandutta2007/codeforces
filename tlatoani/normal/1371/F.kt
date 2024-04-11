import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val s = " " + jin.readLine()
    val segTree = PinballSegtree(n, s)
    val out = StringBuilder()
    for (j in 1..q) {
        val (l, r) = jin.readLine().split(" ").map { it.toInt() }
        segTree.reverse(l, r)
        out.appendln(segTree.query(l, r))
    }
    print(out)
}

data class PinballResult(
        val maxInside: Int,
        val leftOpen: Int,
        val leftClose: Int,
        val rightOpen: Int,
        val rightClose: Int,
        val length: Int
)

val SINGLE_OPEN = PinballResult(1, 1, 0, 1, 1, 1)
val SINGLE_CLOSE = PinballResult(1, 1, 1, 0, 1, 1)

fun combine(left: PinballResult, right: PinballResult) = PinballResult(
        max(max(left.maxInside, right.maxInside),
            max(left.rightOpen + right.leftOpen, left.rightClose + right.leftClose)),
        max(left.leftOpen + (if (left.rightOpen == left.length) right.leftOpen else 0),
                left.leftOpen + (if (left.leftOpen == left.length) right.leftClose else 0)),
        left.leftClose + (if (left.leftClose == left.length) right.leftClose else 0),
        (if (right.rightOpen == right.length) left.rightOpen else 0) + right.rightOpen,
        max((if (right.leftClose == right.length) left.rightClose else 0) + right.rightClose,
                (if (right.rightClose == right.length) left.rightOpen else 0) + right.rightClose),
        left.length + right.length
)

class PinballSegtree(val n: Int, val initial: String) {
    val results = Array(1 shl 20) { PinballResult(0, 0, 0, 0, 0, 0) }
    val resultsRev = Array(1 shl 20) { PinballResult(0, 0, 0, 0, 0, 0) }
    val lazy = BooleanArray(1 shl 20)

    init {
        init(1, 1, n)
    }

    fun init(node: Int, segFrom: Int, segTo: Int) {
        val length = segTo - segFrom + 1
        if (length == 1) {
            if (initial[segFrom] == '>') {
                results[node] = SINGLE_OPEN
                resultsRev[node] = SINGLE_CLOSE
            } else {
                results[node] = SINGLE_CLOSE
                resultsRev[node] = SINGLE_OPEN
            }
        } else {
            val mid = (segFrom + segTo) / 2
            init(2 * node, segFrom, mid)
            init((2 * node) + 1, mid + 1, segTo)
            results[node] = combine(results[2 * node], results[(2 * node) + 1])
            resultsRev[node] = combine(resultsRev[2 * node], resultsRev[(2 * node) + 1])
        }
        //println("results[$node, $segFrom..$segTo] = ${results[node]}")
    }

    fun reverse(from: Int, to: Int) = reverse(from, to, 1, 1, n)

    fun reverse(from: Int, to: Int, node: Int, segFrom: Int, segTo: Int) {
        if (segFrom > to || from > segTo) {
            return
        }
        if (from <= segFrom && segTo <= to) {
            val a = results[node]
            val b = resultsRev[node]
            results[node] = b
            resultsRev[node] = a
            lazy[node] = !lazy[node]
        } else {
            val mid = (segFrom + segTo) / 2
            reverse(from, to, 2 * node, segFrom, mid)
            reverse(from, to, (2 * node) + 1, mid + 1, segTo)
            results[node] = combine(results[2 * node], results[(2 * node) + 1])
            resultsRev[node] = combine(resultsRev[2 * node], resultsRev[(2 * node) + 1])
            if (lazy[node]) {
                val a = results[node]
                val b = resultsRev[node]
                results[node] = b
                resultsRev[node] = a
            }
        }
    }

    fun query(from: Int, to: Int) = query(from, to, 1, 1, n).first.maxInside

    fun query(from: Int, to: Int, node: Int, segFrom: Int, segTo: Int): Pair<PinballResult, PinballResult> {
        if (from <= segFrom && segTo <= to) {
            //println("lazy = ${lazy[node]}")
            //println("query($node, $segFrom..$segTo) = ${Pair(results[node], resultsRev[node])}")
            return Pair(results[node], resultsRev[node])
        } else {
            val mid = (segFrom + segTo) / 2
            var res: Pair<PinballResult, PinballResult>
            if (to <= mid) {
                res = query(from, to, 2 * node, segFrom, mid)
            } else if (from > mid) {
                res = query(from, to, (2 * node) + 1, mid + 1, segTo)
            } else {
                val left = query(from, to, 2 * node, segFrom, mid)
                val right = query(from, to, (2 * node) + 1, mid + 1, segTo)
                res = Pair(combine(left.first, right.first), combine(left.second, right.second))
            }
            if (lazy[node]) {
                res = Pair(res.second, res.first)
            }
            //println("lazy = ${lazy[node]}")
            //println("query($node, $segFrom..$segTo) = $res")
            return res
        }
    }
}

/*
5 0
><>><



 */


/*
5 0
><<><



 */

/*
5 0
<>><>



 */