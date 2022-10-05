import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun ix(chara: Char): Int {
    return when (chara) {
        in 'a'..'z' -> chara - 'a'
        in '0'..'9' -> chara - '0' + 26
        else -> chara - 'A' + 36
    }
}

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    val s = jin.readLine()
    val treeSets = Array(62) { TreeSet<Int>() }
    for (j in 1..n) {
        treeSets[ix(s[j - 1])].add(j)
    }
    val bit = BinaryIndexTree(1, n)
    for (j in 1..n) {
        bit.update(j, 1)
    }
    fun findPos(x: Int): Int {
        var upper = n
        var lower = 1
        while (upper > lower) {
            val mid = (upper + lower) / 2
            if (bit[1, mid] >= x) {
                upper = mid
            } else {
                lower = mid + 1
            }
        }
        return upper
    }
    for (j in 1..m) {
        val line = jin.readLine().split(" ")
        val l = line[0].toInt()
        val r = line[1].toInt()
        val k = ix(line[2][0])
        val a = findPos(l)
        val b = findPos(r)
        var ceil = treeSets[k].ceiling(a)
        while (ceil != null && ceil <= b) {
            treeSets[k].remove(ceil)
            bit.update(ceil, -1)
            ceil = treeSets[k].ceiling(a)
        }
    }
    val out = StringBuilder()
    for (j in 1..n) {
        if (bit[j, j] == 1) {
            out.append(s[j - 1])
        }
    }
    println(out)
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