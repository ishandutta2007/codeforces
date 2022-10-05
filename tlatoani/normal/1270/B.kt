import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tokenizer = StringTokenizer(readLine()!!)
        val array = IntArray(n) { tokenizer.nextToken().toInt() }
        var pos = 0
        var found = false
        for (j in 0 until n) {
            if (array[j] - array[pos] > j - pos) {
                println("YES")
                println("${pos + 1} ${j + 1}")
                found = true
                break
            }
            if (j - pos > array[j] - array[pos]) {
                pos = j
            }
        }
        if (found) {
            continue
        }
        pos = n - 1
        for (j in n - 1 downTo 0) {
            if (array[j] - array[pos] > pos - j) {
                println("YES")
                println("${j + 1} ${pos + 1}")
                found = true
                break
            }
            if (pos - j > array[j] - array[pos]) {
                pos = j
            }
        }
        if (!found) {
            println("NO")
        }
    }
}