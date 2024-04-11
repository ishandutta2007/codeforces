import java.io.BufferedInputStream

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val m = jin.nextInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val odds = mutableSetOf<Int>()
    for (j in 1..n) {
        if (jin.nextInt() == 1) {
            odds.add(j)
        }
    }
    if (odds.isEmpty()) {
        println(0)
    } else {
        val r = odds.min()!!
        val seen = BooleanArray(n + 1)
        val children = Array(n + 1) { mutableListOf<Int>() }
        val ancestors = Array(17) { IntArray(n + 1) }
        val depth = IntArray(n + 1)
        fun recur1(a: Int) {
            for (b in adj[a]) {
                if (!seen[b]) {
                    seen[b] = true
                    ancestors[0][b] = a
                    for (e in 1..16) {
                        ancestors[e][b] = ancestors[e - 1][ancestors[e - 1][b]]
                    }
                    depth[b] = depth[a] + 1
                    children[a].add(b)
                    recur1(b)
                }
            }
            if (children[a].size % 2 == 0) {
                if (a in odds) {
                    odds.remove(a)
                } else {
                    odds.add(a)
                }
            }
        }
        fun lca(a: Int, b: Int): Int {
            var (a, b) = if (depth[a] < depth[b]) Pair(a, b) else Pair(b, a)
            for (e in 16 downTo 0) {
                if (depth[a] + (1 shl e) <= depth[b]) {
                    b = ancestors[e][b]
                }
            }
            if (a == b) {
                return b
            }
            for (e in 16 downTo 0) {
                if (ancestors[e][a] != ancestors[e][b]) {
                    a = ancestors[e][a]
                    b = ancestors[e][b]
                }
            }
            return ancestors[0][a]
        }
        seen[r] = true
        recur1(r)
        for (a in odds) {
            if (!seen[a]) {
                println(-1)
                return
            }
        }
        val extra = if (odds.size % 2 == 1) adj[r][0] else 0
        if (extra != 0) {
            if (extra in odds) {
                odds.remove(extra)
            } else {
                odds.add(extra)
            }
        }
        val dp = IntArray(n + 1)
        val oddsList = odds.toList()
        for (j in oddsList.indices step 2) {
            val a = oddsList[j]
            val b = oddsList[j + 1]
            dp[a]++
            dp[b]++
            dp[lca(a, b)] -= 2
        }
        fun recur2(a: Int) {
            for (b in children[a]) {
                recur2(b)
                dp[a] += dp[b]
            }
        }
        recur2(r)
        var pathLength = 0
        val answer = StringBuilder()
        fun recur3(a: Int) {
            pathLength++
            answer.append(a).append(' ')
            if (dp[a] % 2 == 1) {
                pathLength += 2
                answer.append(ancestors[0][a]).append(' ').append(a).append(' ')
            }
            for (b in children[a]) {
                recur3(b)
                pathLength++
                answer.append(a).append(' ')
            }
        }
        recur3(r)
        if (extra != 0) {
            pathLength++
            answer.append(extra).append(' ')
        }
        println(pathLength)
        println(answer)
    }
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