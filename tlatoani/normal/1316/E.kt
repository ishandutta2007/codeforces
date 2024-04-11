import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val p = tokenizer.nextToken().toInt()
    val k = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(jin.readLine())
    val strengths = LongArray(n) { tokenizer.nextToken().toLong() }
    val specific = Array(n) { j ->
        tokenizer = StringTokenizer(jin.readLine())
        LongArray(p) { tokenizer.nextToken().toLong() }
    }
    val bestAudience = Array(n) { it }.sortedByDescending { strengths[it] }
    val best1 = Array(p) { e -> TreeSet<Int>(Comparator<Int> { j1, j2 ->
        compareValuesBy(j1, j2, { -specific[it][e] }, { it }) }) }
    val best2 = Array(p) { e -> TreeSet<Int>(Comparator<Int> { j1, j2 ->
        compareValuesBy(j1, j2, { -specific[it][e] + strengths[it] }, { it }) }) }
    var answer = 0L
    var curr = 0L
    val audience = mutableSetOf<Int>()
    for (j in 0 until k) {
        curr += strengths[bestAudience[j]]
        audience.add(bestAudience[j])
    }
    for (e in 0 until p) {
        for (j in 0 until n) {
            if (j in audience) {
                best2[e].add(j)
            } else {
                best1[e].add(j)
            }
        }
    }
    val isPlayer = BooleanArray(n)
    for (a in 0..p) {
        var fromIn = 0
        val list2 = Array(p) { d ->
            val res = mutableListOf<Int>()
            var amt = 0
            for (j in best2[d]) {
                if (amt == a) {
                    break
                }
                res.add(j)
                amt++
            }
            res
        }
        val list1 = Array(p) { d ->
            val res = mutableListOf<Int>()
            var amt = a
            for (j in best1[d]) {
                if (amt == p) {
                    break
                }
                res.add(j)
                amt++
            }
            res
        }
        fun recur(d: Int) {
            if (fromIn > a || fromIn + p - d < a) {
                return
            }
            if (d == p) {
                if (fromIn == a) {
                    answer = max(answer, curr)
                }
            } else {
                fromIn++
                for (j in list2[d]) {
                    if (!isPlayer[j]) {
                        isPlayer[j] = true
                        curr += specific[j][d] - strengths[j]
                        recur(d + 1)
                        curr -= specific[j][d] - strengths[j]
                        isPlayer[j] = false
                    }
                }
                fromIn--
                for (j in list1[d]) {
                    if (!isPlayer[j]) {
                        isPlayer[j] = true
                        curr += specific[j][d]
                        recur(d + 1)
                        curr -= specific[j][d]
                        isPlayer[j] = false
                    }
                }
            }
        }
        recur(0)
        if (a < p) {
            curr += strengths[bestAudience[k + a]]
            audience.add(bestAudience[k + a])
            for (e in 0 until p) {
                best1[e].remove(bestAudience[k + a])
                best2[e].add(bestAudience[k + a])
            }
        }
    }
    println(answer)
}