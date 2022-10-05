import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val array = intArrayOf(0) + jin.readLine().split(" ").map { it.toInt() }.toIntArray()
        val answer = mutableListOf<Int>()
        val present = BooleanArray(n + 1)
        var rem = 0
        for (j in 1..n) {
            if (array[j] != j - 1) {
                rem++
            }
        }
        while (rem > 0) {
            present.fill(false)
            for (k in 1..n) {
                present[array[k]] = true
            }
            var mex = 0
            while (present[mex]) {
                mex++
            }
            if (mex == n) {
                for (k in 1..n) {
                    if (array[k] != k - 1) {
                        array[k] = n
                        answer.add(k)
                        break
                    }
                }
            } else {
                array[mex + 1] = mex
                answer.add(mex + 1)
                rem--
            }
        }
        out.appendln(answer.size)
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}