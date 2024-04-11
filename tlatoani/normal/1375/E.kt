import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val array = intArrayOf(0) + IntArray(n) { tokenizer.nextToken().toInt() }
    val ixs = (1..n).sortedWith(compareBy({ array[it] }, { it }))
    var m = 0
    val out = StringBuilder()
    val list = mutableListOf<Int>()
    for (j in ixs) {
        for (k in 0 until list.size) {
            if (list[k] < j) {
                list.add(k, j)
                break
            } else {
                m++
                out.appendln("$j ${list[k]}")
            }
        }
        if (list.isEmpty() || list.last() > j) {
            list.add(j)
        }
    }
    println(m)
    print(out)
}