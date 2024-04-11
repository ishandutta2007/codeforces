import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val treeMap = TreeMap<Int, Int>()
        treeMap[n + 1] = -1
        val tokenizer = StringTokenizer(jin.readLine())
        val seen = BooleanArray(n + 1)
        for (j in 1..n) {
            val k = tokenizer.nextToken().toInt()
            if (seen[k]) {
                treeMap.remove(k)
            } else {
                seen[k] = true
                treeMap[k] = j
            }
        }
        out.appendln(treeMap.firstEntry()!!.value!!)
    }
    print(out)
}