import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val queries = Array(n) {
        val tokenizer = StringTokenizer(jin.readLine())
        val type = tokenizer.nextToken()[0]
        val x = tokenizer.nextToken().toInt()
        val y = tokenizer.nextToken().toInt()
        Query(type, x, y)
    }
    val xs = ArrayList<Int>(n)
    for (query in queries) {
        xs.add(query.x)
    }
    xs.sort()
    val xix = HashMap<Int, Int>(n)
    val ixx = IntArray(n + 1)
    var ix = 0
    val freq = IntArray(n + 1) { 1 }
    for (j in 0 until n) {
        if (j == 0 || xs[j] != xs[j - 1]) {
            ix++
            xix[xs[j]] = ix
            ixx[ix] = xs[j]
        } else {
            freq[ix]++
        }
    }
    val treeSets = Array(n + 1) {
        val res = TreeSet<Int>()
        res.add(0)
        res
    }
    val out = StringBuilder()
    val segTree = SegmentTree(1, ix)
    for (query in queries) {
        when (query.type) {
            'a' -> {
                val k = xix[query.x]!!
                treeSets[k].add(query.y)
                segTree.update(k, treeSets[k].last())
            }
            'r' -> {
                val k = xix[query.x]!!
                treeSets[k].remove(query.y)
                segTree.update(k, treeSets[k].last())
            }
            'f' -> {
                val k = xix[query.x]!!
                if (segTree.query(k + 1, ix) <= query.y) {
                    out.appendln(-1)
                } else {
                    var upper = ix
                    var lower = k + 1
                    while (upper > lower) {
                        val mid = (upper + lower) / 2
                        if (segTree.query(k + 1, mid) > query.y) {
                            upper = mid
                        } else {
                            lower = mid + 1
                        }
                    }
                    out.append(ixx[upper]).append(' ').appendln(treeSets[upper].higher(query.y)!!)
                }
            }
        }
    }
    print(out)
}

class Query(val type: Char, val x: Int, val y: Int)

class SegmentTree(val treeFrom: Int, treeTo: Int) {
    val value: IntArray
    val length: Int

    fun update(index: Int, delta: Int) {
        var node = index - treeFrom + length
        value[node] = delta
        node = node shr 1
        while (node > 0) {
            value[node] = max(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    fun query(from: Int, to: Int): Int {
        var from = from
        var to = to
        if (to < from) {
            return 0
        }
        from += length - treeFrom
        to += length - treeFrom + 1
        var res = 0
        while (from + (from and -from) <= to) {
            res = max(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = max(res, value[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }

    init {
        val length = treeTo - treeFrom + 1
        var l: Int
        l = 0
        while (1 shl l < length) {
            l++
        }
        value = IntArray(1 shl l + 1)
        this.length = 1 shl l
    }
}