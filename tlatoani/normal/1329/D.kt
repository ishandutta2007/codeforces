import java.util.*

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val rem = TreeSet<Int>()
        rem.addAll(1..s.length)
        val bit = BinaryIndexTree(1, s.length)
        for (k in 1..s.length) {
            bit.update(k, 1)
        }
        val removals = mutableListOf<Pair<Int, Int>>()
        val disp = TreeSet<Int>()
        disp.addAll((1 until s.length).filter { k -> s[k - 1] == s[k] })
        val dispBy = Array(26) { ArrayDeque<Int>() }
        val freq = IntArray(26)
        for (k in disp) {
            dispBy[s[k] - 'a'].push(k)
            freq[s[k] - 'a']++
        }
        fun remove(from: Int, to: Int) {
            removals.add(Pair(bit.query(from) + 1, bit.query(to)))
            while (rem.floor(to) ?: 0 > from) {
                bit.update(rem.floor(to)!!, -1)
                rem.remove(rem.floor(to)!!)
            }
            disp.remove(from)
            disp.remove(to)
            disp.lower(from)?.let { l -> dispBy[s[l] - 'a'].add(l) }
            disp.higher(to)?.let { l -> dispBy[s[l] - 'a'].add(l) }
            if (from > 0) {
                freq[s[from] - 'a']--
            }
            if (to < s.length) {
                freq[s[to] - 'a']--
            }
        }
        while (true) {
            val letter = ('a'..'z').maxBy { freq[it - 'a'] }!!
            var found = false
            while (dispBy[letter - 'a'].isNotEmpty()) {
                val k = dispBy[letter - 'a'].pop()
                if (k in disp) {
                    var j = disp.lower(k)
                    if (j != null && s[j] != s[k]) {
                        remove(j, k)
                        found = true
                        break
                    }
                    j = disp.higher(k)
                    if (j != null && s[j] != s[k]) {
                        remove(k, j)
                        found = true
                        break
                    }
                }
            }
            if (!found) {
                break
            }
        }
        for (k in disp.toList()) {
            remove(0, k)
        }
        remove(0, s.length)
        out.appendln(removals.size)
        removals.forEach { (from, to) -> out.appendln("$from $to") }
    }
    print(out)
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