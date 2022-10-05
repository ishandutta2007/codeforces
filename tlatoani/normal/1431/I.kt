import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

val MOD = "960000809\t960000851\t960000883\t960000907\t960000913\t960000941\t960000947\t960000971\t960000983\t960001037\t960002347\t960002353\t960002357\t960002377\t960002383\t960002387\t960002423\t960002437\t960002441\t960002479".split("\t").shuffled()[0].toLong()
val BASE = "3911\t3917\t3919\t3923\t3929\t3931\t3943\t3947\t3967\t3989\t4421\t4423\t4441\t4447\t4451\t4457\t4463\t4481\t4483\t4493".split("\t").shuffled()[0].toLong()

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, q) = jin.readLine().split(" ").map { it.toInt() }
    val pow = LongArray(m + 1)
    pow[0] = 1L
    for (j in 1..m) {
        pow[j] = (BASE * pow[j - 1]) % MOD
    }
    val matrix = Array(n) { jin.readLine() }
    fun prefixHash(s: String): LongArray {
        val res = LongArray(m + 1)
        for (j in 1..m) {
            res[j] = (res[j - 1] + (pow[j] * (s[j - 1] - 'a').toLong())) % MOD
        }
        return res
    }
    val hashes = Array(n) { prefixHash(matrix[it]) }
    fun lcp(suffix1: Suffix, suffix2: Suffix): Int {
        val j = suffix1.from
        var upper = m
        var lower = j
        while (upper > lower) {
            val mid = (upper + lower + 1) / 2
            if ((suffix1.hashes[mid] - suffix1.hashes[j] - suffix2.hashes[mid] + suffix2.hashes[j]) % MOD == 0L) {
                lower = mid
            } else {
                upper = mid - 1
            }
        }
        return upper
    }
    val comparator = Comparator<Suffix> { suffix1, suffix2 ->
        val l = lcp(suffix1, suffix2)
        if (l == m) 0 else (suffix1.string[l].compareTo(suffix2.string[l]))
    }
    val suffixArrays = Array(m) { j -> Array(n) { y -> Suffix(j, matrix[y], hashes[y]) } }
    suffixArrays.forEach { it.sortWith(comparator) }
    val out = StringBuilder()
    for (k in 1..q) {
        val s = jin.readLine()
        val hash = prefixHash(s)
        var res = -1
        var j = 0
        while (j < m) {
            val suffix = Suffix(j, s, hash)
            var upper = n - 1
            var lower = 0
            while (upper > lower) {
                val mid = (upper + lower + 1) / 2
                if (comparator.compare(suffix, suffixArrays[j][mid]) >= 0) {
                    lower = mid
                } else {
                    upper = mid - 1
                }
            }
            var jn = lcp(suffix, suffixArrays[j][upper])
            //println("suffix = $suffix, array thing = ${suffixArrays[j][upper]}, jn = $jn")
            if (upper < n - 1) {
                jn = max(jn, lcp(suffix, suffixArrays[j][upper + 1]))
            }
            if (jn == j) {
                res = -1
                break
            }
            j = jn
            res++
        }
        out.appendln(res)
    }
    print(out)
}

class Suffix(val from: Int, val string: String, val hashes: LongArray) {
    override fun toString(): String {
        return "Suffix(from=$from, string='$string', hashes=${hashes.contentToString()})"
    }
}