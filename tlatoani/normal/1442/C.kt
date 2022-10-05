import java.io.BufferedInputStream
import java.util.*
import kotlin.math.min

const val MOD = 998244353L

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val m = jin.nextInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    val rev = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        adj[a].add(b)
        rev[b].add(a)
    }
    var next = mutableListOf<Int>()
    next.add(1)
    var nextDist = IntArray(n + 1) { Int.MAX_VALUE }
    nextDist[1] = 0
    var answer = Int.MAX_VALUE
    val q = LinkedList<Int>()
    for (p in 0..19) {
        val dist = nextDist
        nextDist = IntArray(n + 1) { Int.MAX_VALUE }
        nextDist.fill(Int.MAX_VALUE)
        val curr = next
        next = mutableListOf()
        q.add(curr[0])
        var j = 1
        while (q.isNotEmpty() || j < curr.size) {
            if (q.isEmpty()) {
                q.add(curr[j])
                j++
            }
            val a = q.remove()
            while (j < curr.size && dist[curr[j]] <= dist[a]) {
                if (dist[curr[j]] == dist[a]) {
                    q.add(curr[j])
                }
                j++
            }
            nextDist[a] = dist[a] + (1 shl p)
            next.add(a)
            for (b in (if (p and 1 == 0) adj else rev)[a]) {
                if (dist[a] + 1 < dist[b]) {
                    dist[b] = dist[a] + 1
                    q.add(b)
                }
            }
        }
        answer = min(answer, dist[n])
    }
    if (answer != Int.MAX_VALUE) {
        println(answer)
        return
    }
    val dist = LongArray((2 * n) + 1) { Long.MAX_VALUE }
    dist[1] = 0L
    val seen = BooleanArray((2 * n) + 1)
    val pq = PriorityQueue<Node>(compareBy { it.dist })
    pq.add(Node(1, 0L))
    while (pq.isNotEmpty()) {
        val (a, d) = pq.remove()
        if (a == n || a == 2 * n) {
            val lambda = d shr 20
            var answer = d % (1L shl 20)
            var pow2 = 1L
            for (j in 1L..lambda) {
                pow2 *= 2L
                pow2 %= MOD
            }
            pow2--
            answer += pow2
            answer %= MOD
            println(answer)
            return
        }
        if (!seen[a]) {
            seen[a] = true
            if (a <= n && d + (1L shl 20) < dist[a + n]) {
                dist[a + n] = d + (1L shl 20)
                pq.add(Node(a + n, dist[a + n]))
            }
            if (a > n && d + (1L shl 20) < dist[a - n]) {
                dist[a - n] = d + (1L shl 20)
                pq.add(Node(a - n, dist[a - n]))
            }
            for (b in (if (a <= n) adj[a] else rev[a - n])) {
                val b = if (a <= n) b else (b + n)
                if (d + 1L < dist[b]) {
                    dist[b] = d + 1L
                    pq.add(Node(b, dist[b]))
                }
            }
        }
    }
}

data class Node(val a: Int, val dist: Long)

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