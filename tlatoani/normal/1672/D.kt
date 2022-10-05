import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val aTokenizer = StringTokenizer(readLine()!!)
        val bTokenizer = StringTokenizer(readLine()!!)
        val stored = IntArray(n + 1)
        var last = 0
        var answer = "yEs"
        for (j in 1..n) {
            val b = bTokenizer.nextToken().toInt()
            if (b == last && stored[b] > 0) {
                stored[b]--
            } else {
                var found = false
                while (aTokenizer.hasMoreTokens()) {
                    val a = aTokenizer.nextToken().toInt()
                    if (a == b) {
                        found = true
                        break
                    }
                    stored[a]++
                }
                if (!found) {
                    answer = "nO"
                    break
                }
            }
            last = b
        }
        println(answer)
    }
}