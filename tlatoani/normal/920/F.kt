import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val factors = IntArray(1000001)
    for (f in 1..1000000) {
        var k = f
        while (k <= 1000000) {
            factors[k]++
            k += f
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ").map { it.toInt() }
    val n = line[0]
    val m = line[1]
    val array = ("0 " + jin.readLine()).split(" ").map { it.toInt() }.toMutableList()
    val bit = BinaryIndexTree(1, n)
    val rem = TreeSet<Int>()
    rem.add(n + 1)
    for (j in 1..n) {
        bit.update(j, array[j].toLong())
        if (array[j] > 2) {
            rem.add(j)
        }
    }
    val out = StringBuilder()
    for (j in 1..m) {
        val line = jin.readLine().split(" ").map { it.toInt() }
        if (line[0] == 1) {
            var j = rem.ceiling(line[1])
            while (j <= line[2]) {
                bit.update(j, (factors[array[j]] - array[j]).toLong())
                array[j] = factors[array[j]]
                if (array[j] <= 2) {
                    rem.remove(j)
                }
                j = rem.higher(j)
            }
        } else {
            out.appendln(bit[line[1], line[2]])
        }
    }
    print(out)
}

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = LongArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Long) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Long {
        var res = 0L
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            i -= i and -i
        }
        return res
    }

    operator fun get(from: Int, to: Int) = if (to < from) 0L else query(to) - query(from - 1)
}