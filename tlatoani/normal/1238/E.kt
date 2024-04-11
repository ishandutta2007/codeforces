import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val s = jin.readLine()
    val freq = Array(m) { IntArray(m) }
    for (j in 1 until n) {
        freq[s[j - 1] - 'a'][s[j] - 'a']++
        freq[s[j] - 'a'][s[j - 1] - 'a']++
    }
    val addend = IntArray(1 shl m) { -1 }
    val dp = IntArray(1 shl m) { Int.MAX_VALUE }
    addend[0] = 0
    dp[0] = 0
    for (mask in 1 until (1 shl m)) {
        for (e in 0 until m) {
            if ((mask shr e) and 1 != 0) {
                dp[mask] = min(dp[mask], dp[mask - (1 shl e)])
                if (addend[mask] == -1) {
                    addend[mask] = addend[mask - (1 shl e)]
                    for (f in 0 until m) {
                        if (f == e) {
                            Unit
                        } else if ((mask shr f) and 1 == 0) {
                            addend[mask] += freq[e][f]
                        } else {
                            addend[mask] -= freq[e][f]
                        }
                    }
                }
            }
        }
        dp[mask] += addend[mask]
    }
    println(dp[(1 shl m) - 1])
}