import kotlin.math.max
import kotlin.math.min

const val MOD = 998244353L

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val words = Array(n) { readLine()!! }
    val position = Array(5) { Array(5) { IntArray(n) } }
    var ix = 0
    for (a in 0..4) {
        for (b in 0..4) {
            for (j in 0 until n) {
                if (a <= b) {
                    position[a][b][j] = ix
                    ix++
                }
            }
        }
    }
    val transition = Array(30) { Array(ix) { LongArray(ix) } }
    for (a in 0..4) {
        for (b in 0..4) {
            for (j in 0 until n) {
                if (a <= b && b - a <= words[j].length) {
                    val x = position[a][b][j]
                    val rem = words[j].substring(words[j].length - (b - a))
                    if (b == 4) {
                        for (k in 0 until n) {
                            if (words[k].startsWith(rem) || rem.startsWith(words[k])) {
                                if (a == 4) {
                                    for (k2 in 0 until n) {
                                        if (words[k].startsWith(words[k2]) || words[k2].startsWith(words[k])) {
                                            val u = 5 - words[k].length
                                            val v = 5 - words[k2].length
                                            transition[0][x][position[min(u, v)][max(u, v)][if (words[k].length > words[k2].length) k else k2]]++
                                        }
                                    }
                                } else {
                                    val c = a + 1
                                    val d = 5 - words[k].length
                                    transition[0][x][position[min(c, d)][max(c, d)][if (c < d) j else k]]++
                                }
                            }
                        }
                    } else {
                        transition[0][x][position[a + 1][b + 1][j]]++
                    }
                }
            }
        }
    }
    for (d in 1..29) {
        transition[d] = multiply(transition[d - 1], transition[d - 1])
    }
    var vector = Array(1) { LongArray(ix) }
    vector[0][position[0][0][0]] = 1L
    for (d in 0..29) {
        if ((m + 4) and (1 shl d) != 0) {
            vector = multiply(vector, transition[d])
        }
    }
    var answer = 0L
    for (j in 0 until n) {
        answer += vector[0][position[4][4][j]]
    }
    answer %= MOD
    println(answer)
}

fun multiply(a: Array<LongArray>, b: Array<LongArray>): Array<LongArray> {
    val res = Array(a.size) { LongArray(b[0].size) }
    for (j in a.indices) {
        for (k in b.indices) {
            for (l in b[0].indices) {
                res[j][l] += a[j][k] * b[k][l]
                res[j][l] %= MOD
            }
        }
    }
    return res
}