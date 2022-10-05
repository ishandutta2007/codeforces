import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val s = jin.readLine()
    val out = StringBuilder()
    val segTree = SegmentTree(0, s.length - 1)
    for (j in 0 until s.length) {
        segTree.update(j, 1L shl (s[j] - 'a'))
    }
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        val l = line.substring(0, six).toInt() - 1
        val r = line.substring(six + 1).toInt() - 1
        if (r == l) {
            out.appendln("Yes")
        } else if (s[l] != s[r]) {
            out.appendln("Yes")
        } else {
            val mask = segTree.query(l, r)
            var amt = 0
            for (e in 0 until 26) {
                if ((mask and (1L shl e)) != 0L) {
                    amt++
                }
            }
            if (amt >= 3) {
                out.appendln("Yes")
            } else {
                out.appendln("No")
            }
        }
    }
    print(out)
}

class SegmentTree(val treeFrom: Int, treeTo: Int) {
    val `val`: LongArray
    val length: Int
    fun update(index: Int, delta: Long) {
        var node = index - treeFrom + length
        `val`[node] = delta
        node = node shr 1
        while (node > 0) {
            `val`[node] = `val`[node shl 1] or `val`[(node shl 1) + 1]
            node = node shr 1
        }
    }

    fun query(from: Int, to: Int): Long {
        var from = from
        var to = to
        if (to < from) {
            return 0
        }
        from += length - treeFrom
        to += length - treeFrom + 1
        var res: Long = 0
        while (from + (from and -from) <= to) {
            res = res or `val`[from / (from and -from)]
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = res or `val`[(to - (to and -to)) / (to and -to)]
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
        `val` = LongArray(1 shl l + 1)
        this.length = 1 shl l
    }
}