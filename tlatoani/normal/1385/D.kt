import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val s = jin.readLine().map { it - 'a' }
        fun recur(from: Int, to: Int): IntArray {
            val res = IntArray(26) { Int.MAX_VALUE }
            if (from + 1 == to) {
                res.fill(1)
                res[s[from]] = 0
            } else {
                val left = recur(from, (from + to) / 2)
                val right = recur((from + to) / 2, to)
                for (chara in 0..24) {
                    val leftRem = (from until (from + to) / 2).count { s[it] != chara }
                    val rightRem = ((from + to) / 2 until to).count { s[it] != chara }
                    if (right[chara + 1] != Int.MAX_VALUE) {
                        res[chara] = leftRem + right[chara + 1]
                    }
                    if (left[chara + 1] != Int.MAX_VALUE) {
                        res[chara] = min(res[chara], left[chara + 1] + rightRem)
                    }
                }
            }
            return res
        }
        out.appendln(recur(0, n)[0])
    }
    print(out)
}