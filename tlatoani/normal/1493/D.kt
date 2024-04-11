import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MOD = 1000000007L

fun main() {
    val lastPrime = IntArray(200001)
    for (p in 2..200000) {
        if (lastPrime[p] == 0) {
            for (k in p..200000 step p) {
                lastPrime[k] = p
            }
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val appearances = Array(200001) { mutableListOf<Int>() }
    var answer = 1L
    val factorization = Array(n + 1) { mutableMapOf<Int, Int>() }
    val tokenizer = StringTokenizer(jin.readLine())
    fun increment(j: Int, p: Int) {
        val f = factorization[j][p] ?: 0
        if (appearances[p].size == f) {
            appearances[p].add(1)
        } else {
            appearances[p][f]++
        }
        if (appearances[p][f] == n) {
            answer *= p.toLong()
            answer %= MOD
        }
        factorization[j][p] = f + 1
    }
    fun multiply(j: Int, k: Int) {
        var k = k
        while (k != 1) {
            increment(j, lastPrime[k])
            k /= lastPrime[k]
        }
    }
    for (j in 1..n) {
        multiply(j, tokenizer.nextToken().toInt())
    }
    val out = StringBuilder()
    for (a in 1..q) {
        val (j, k) = jin.readLine().split(" ").map { it.toInt() }
        multiply(j, k)
        out.appendln(answer)
    }
    print(out)
}