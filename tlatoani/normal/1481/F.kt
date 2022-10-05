import java.io.BufferedInputStream
import kotlin.math.max

const val MOD = 998244853

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val x = jin.nextInt()
    val children = Array(n + 1) { mutableListOf<Int>() }
    for (a in 2..n) {
        children[jin.nextInt()].add(a)
    }
    val depth = IntArray(n + 1)
    val freq = IntArray(n)
    val maxDepth = IntArray(n + 1) { 1 }
    maxDepth[0] = 0
    fun dfs(a: Int) {
        for (b in children[a]) {
            depth[b] = depth[a] + 1
            dfs(b)
            maxDepth[a] = max(maxDepth[a], maxDepth[b] + 1)
        }
        freq[depth[a]]++
    }
    dfs(1)
    val freqs = IntArray(n + 1)
    for (d in 0 until n) {
        freqs[freq[d]]++
    }
    val ways = Array(2) { IntArray(n + 1) }
    ways[0][0] = 1
    for (f in 1..n) {
        if (freqs[f] > 0) {
            for (j in 0..n) {
                ways[1][j] = ways[0][j]
                if (j >= f) {
                    ways[1][j] += ways[1][j - f]
                }
                if (j >= f * freqs[f]) {
                    ways[1][j] -= ways[0][j - (f * freqs[f])]
                }
                if (ways[1][j] >= MOD) {
                    ways[1][j] -= MOD
                } else if (ways[1][j] < 0) {
                    ways[1][j] += MOD
                }
            }
            for (j in 0..n) {
                ways[0][j] = ways[1][j]
                if (j >= f) {
                    ways[0][j] += ways[1][j - f]
                    if (ways[0][j] >= MOD) {
                        ways[0][j] -= MOD
                    }
                }
            }
        }
    }
    //println(ways[0].contentToString())
    val dummy = IntArray(0)
    val waysReduced = Array(n + 1) { dummy }
    for (f in 1..n) {
        if (freqs[f] > 0) {
            waysReduced[f] = IntArray(n + 1)
            for (j in 0..n) {
                waysReduced[f][j] = ways[0][j]
                if (j >= f) {
                    waysReduced[f][j] -= waysReduced[f][j - f]
                }
                if (waysReduced[f][j] < 0) {
                    waysReduced[f][j] += MOD
                }
            }
            //println("waysReduced[$f] = ${waysReduced[f].contentToString()}")
        }
    }
    //println(ways[q].contentToString())
    val eachDepth = Array(n) { mutableListOf(0) }
    for (a in 1..n) {
        eachDepth[depth[a]].add(a)
    }
    fun checkPossible(j: Int, notIncluding: Int) = j in 0..n && waysReduced[freq[notIncluding]][j] != 0
    var optimal = n + 1
    var optimalD = 0
    var optimalJ = 0
    var optimalDir = true
    for (d in 0 until n) {
        if (freq[d] > 0) {
            eachDepth[d].sortBy { a -> maxDepth[a] }
            for ((j, a) in eachDepth[d].withIndex()) {
                //println("d = $d, freq = ${freq[d]}, j = $j, a = $a")
                if (maxDepth[a] < optimal) {
                    if (checkPossible(x - j, d)) {
                        optimal = maxDepth[a]
                        optimalD = d
                        optimalJ = j
                        optimalDir = false
                    } else if (checkPossible(x + j - freq[d], d)) {
                        optimal = maxDepth[a]
                        optimalD = d
                        optimalJ = j
                        optimalDir = true
                    }
                }
            }
        }
    }
    //println("penalty = $optimal, d =  $optimalD, j = $optimalJ, dir = $optimalDir")
    freqs[freq[optimalD]]--
    val prev = IntArray(n + 1) { -1 }
    val usedF = IntArray(n + 1)
    prev[0] = -2
    for (f in 1..n) {
        if (freqs[f] > 0) {
            for (j in f..n) {
                if (prev[j] == -1 && prev[j - f] != -1) {
                    if (usedF[j - f] != f) {
                        prev[j] = j - f
                        usedF[j] = f
                    } else if (prev[j - f] >= j - (f * freqs[f])) {
                        prev[j] = prev[j - f]
                        usedF[j] = f
                    }
                }
            }
        }
    }
    val answer = CharArray(n + 1) { 'b' }
    var k = if (optimalDir) (x + optimalJ - freq[optimalD]) else (x - optimalJ)
    val buckets = Array(n) { mutableListOf<Int>() }
    for (d in 0 until n) {
        if (d != optimalD) {
            for (a in eachDepth[d]) {
                if (a != 0) {
                    buckets[freq[d]].add(a)
                }
            }
        }
    }
    //println(buckets.contentToString())
    while (k != 0) {
        //println("k = $k, prev = ${prev[k]}, usedF = ${usedF[k]},")
        for (j in 0 until k - prev[k]) {
            answer[buckets[usedF[k]][j]] = 'a'
        }
        k = prev[k]
    }
    for (j in 1 until eachDepth[optimalD].size) {
        if (j > optimalJ == optimalDir) {
            answer[eachDepth[optimalD][j]] = 'a'
        }
    }
    println(maxDepth[1] + optimal)
    println(String(answer).substring(1))
}

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
}

/*
9 2
1 1 1 3 4 2 4 3

 */