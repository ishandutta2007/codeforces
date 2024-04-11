import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        val (n, q) = jin.readLine().split(" ").map { it.toInt() }
        val s = "0" + jin.readLine()
        val f = "0" + jin.readLine()
        val queries = Stack<Int>()
        for (j in 1..q) {
            val (l, r) = jin.readLine().split(" ").map { it.toInt() }
            queries.push(l)
            queries.push(r)
        }
        val treeMap = TreeMap<Int, Int>()
        for (j in 0..n) {
            treeMap[j] = f[j] - '0'
        }
        while (queries.isNotEmpty()) {
            val r = queries.pop()
            val l = queries.pop()
            treeMap[l - 1] = treeMap.ceilingEntry(l - 1)!!.value
            var amt1 = 0
            var j = r
            var last = treeMap.ceilingEntry(r)!!.value
            while (j >= l) {
                val floor = treeMap.floorEntry(j)!!
                if (last == 1) {
                    amt1 += j - floor.key
                }
                j = floor.key
                last = floor.value
                if (j >= l) {
                    treeMap.remove(j)
                }
            }
            if (2 * amt1 < r - l + 1) {
                treeMap[r] = 0
            } else if (2 * amt1 == r - l + 1) {
                out.appendln("nO")
                continue@cases
            } else {
                treeMap[r] = 1
            }
        }
        out.appendln(if ((1..n).all { j -> treeMap.ceilingEntry(j)!!.value == s[j] - '0' }) "yEs" else "nO")
    }
    print(out)
}