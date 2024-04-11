import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

const val P = 29L
const val MOD = 998244853L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = BufferedWriter(OutputStreamWriter(System.`out`))
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        val n = s.length
        var j = 0
        while (j < n - j - 1 && s[j] == s[n - j - 1]) {
            j++
        }
        //println("j = $j")
        var k = j
        var bestK = k
        var forwardHash = 0L
        var backwardHash = 0L
        var pow = 1L
        while (k <= n - j - 1) {
            forwardHash *= P
            forwardHash += (s[k] - 'a').toLong()
            forwardHash %= MOD
            backwardHash += (s[k] - 'a').toLong() * pow
            backwardHash %= MOD
            pow *= P
            pow %= MOD
            k++
            if (forwardHash == backwardHash) {
                //println("from beginning, bestK = $k")
                bestK = k
            }
        }
        val candidate1 = s.substring(0, bestK) + s.substring(n - j)
        k = n - j - 1
        bestK = k
        forwardHash = 0L
        backwardHash = 0L
        pow = 1L
        while (k >= j) {
            forwardHash *= P
            forwardHash += (s[k] - 'a').toLong()
            forwardHash %= MOD
            backwardHash += (s[k] - 'a').toLong() * pow
            backwardHash %= MOD
            pow *= P
            pow %= MOD
            k--
            if (forwardHash == backwardHash) {
                //println("from end, bestK = $k")
                bestK = k
            }
        }
        val candidate2 = s.substring(0, j) + s.substring(bestK + 1)
        if (candidate1.length > candidate2.length) {
            out.appendln(candidate1)
        } else {
            out.appendln(candidate2)
        }
    }
    out.flush()
    out.close()
}

/*
1
abcdfdcecba

 */