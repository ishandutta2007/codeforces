import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val prev = Array(n + 1) { LinkedList<Int>() }
    var answer = 0L
    val tokenizer = StringTokenizer(jin.readLine())
    val segTree = ZeroSegmentTree(n)
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        if (prev[k].size >= 3) {
            segTree.update((if (prev[k].size >= 4) prev[k][3] else 0) + 1, prev[k][2], 1)
        }
        prev[k].addFirst(j)
        segTree.update((if (prev[k].size >= 2) prev[k][1] else 0) + 1, j, 1)
        if (prev[k].size >= 3) {
            segTree.update((if (prev[k].size >= 4) prev[k][3] else 0) + 1, prev[k][2], -1)
        }
        answer += (segTree.query() - (n - j)).toLong()
        //println("j = $j, query = ${segTree.query()}")
    }
    println(answer)
}

class ZeroSegmentTree(val n: Int) {
    val min = IntArray(1 shl 20)
    val freq = IntArray(1 shl 20)
    val lazy = IntArray(1 shl 20)

    init {
        init(1, 1, n)
    }

    fun init(node: Int, segFrom: Int, segTo: Int) {
        freq[node] = segTo - segFrom + 1
        if (segFrom < segTo) {
            val left = 2 * node
            val right = (2 * node) + 1
            val mid = (segFrom + segTo) / 2
            init(left, segFrom, mid)
            init(right, mid + 1, segTo)
        }
    }

    fun update(from: Int, to: Int, delta: Int) = update(from, to, delta, 1, 1, n)

    fun update(from: Int, to: Int, delta: Int, node: Int, segFrom: Int, segTo: Int) {
        if (to < segFrom || segTo < from) {

        } else if (from <= segFrom && segTo <= to) {
            min[node] += delta
            lazy[node] += delta
        } else {
            val left = 2 * node
            val right = (2 * node) + 1
            min[left] += lazy[node]
            lazy[left] += lazy[node]
            min[right] += lazy[node]
            lazy[right] += lazy[node]
            lazy[node] = 0
            val mid = (segFrom + segTo) / 2
            update(from, to, delta, left, segFrom, mid)
            update(from, to, delta, right, mid + 1, segTo)
            if (min[left] < min[right]) {
                min[node] = min[left]
                freq[node] = freq[left]
            } else if (min[left] == min[right]) {
                min[node] = min[left]
                freq[node] = freq[left] + freq[right]
            } else {
                min[node] = min[right]
                freq[node] = freq[right]
            }
        }
    }

    fun query() = if (min[1] == 0) freq[1] else 0
}