import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val missingSums = IntArray(n + 1) { 1 }
        val freqs = mutableMapOf<Int, Int>()
        for (x in readLine()!!.split(" ").map { it.toInt() }) {
            if (x <= n) {
                missingSums[x] = 0
            }
            freqs[x] = (freqs[x] ?: 0) + 1
        }
        for (mex in 1..n) {
            missingSums[mex] += missingSums[mex - 1]
        }
        val entries = freqs.entries.map { (key, value) -> Frequency(key, value) }.sortedBy { it.number }
        var index = entries.lastIndex
        val byFreq = entries.sortedBy { it.frequency }
        for ((j, freq) in byFreq.withIndex()) {
            freq.index = j + 1
        }
        val bitFreqs = BinaryIndexTree(0, n)
        val bitPresent = BinaryIndexTree(0, n)
        var answer = n
        for (mex in n downTo 0) {
            while (index >= 0 && entries[index].number >= mex) {
                bitFreqs.update(entries[index].index, entries[index].frequency)
                bitPresent.update(entries[index].index, 1)
                index--
            }
            val missing = if (mex == 0) 0 else missingSums[mex - 1]
            if (missing <= k) {
                var upper = n
                var lower = 0
                while (upper > lower) {
                    val mid = (upper + lower + 1) / 2
                    if (bitFreqs[0, mid] <= k) {
                        lower = mid
                    } else {
                        upper = mid - 1
                    }
                }
                answer = min(answer, bitPresent[upper + 1, n])
            }
        }
        println(answer)
    }
}

class Frequency(val number: Int, val frequency: Int) {
    var index = -1
}

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = IntArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Int) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Int {
        var res = 0
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            i -= i and -i
        }
        return res
    }

    operator fun get(from: Int, to: Int) = if (to < from) 0 else query(to) - query(from - 1)
}