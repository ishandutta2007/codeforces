//package kh8
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class G2 {
    fun solve() {
        var (n, m) = na()
        var dp = LongArray(m+1)
        Arrays.fill(dp, Long.MIN_VALUE / 2)
        dp[m] = 0

        var ab = mutableListOf<IntArray>()
        for(i in 0..n-1) {
            var K = ni()
            var a = na().toIntArray()
            var b = na().toIntArray()
            for(j in 0..K-1){
                ab.add(intArrayOf(i+1, b[j], a[j]))
            }
        }

        var comp = compareBy<IntArray> { it[0] + it[1] }
            .thenBy {it[1]}
        var abb = ab.sortedWith(comp)

        var st = SegmentTreeRMQL(m+1)
        st.update(m, 0L)

        for(u in abb){
            var nv = -st.min(u[1], Math.min(u[0]+u[1], m+1)) + u[2]
            st.update(u[1], -nv)
        }

        out.println(-st.min(0, m+1))
    }

    class SegmentTreeRMQL(val N: Int) {
        val M: Int
        val H: Int
        var vals: LongArray

        constructor(a: IntArray) : this(a.size) {
            for (i in 0 until N) {
                vals[H + i] = a[i].toLong()
            }
            //		Arrays.fill(vals, H+N, M, I);
            for (i in H - 1 downTo 1) propagate(i)
        }

        fun update(pos: Int, x: Long) {
            vals[H + pos] = x
            var i = H + pos ushr 1
            while (i >= 1) {
                propagate(i)
                i = i ushr 1
            }
        }

        private fun propagate(i: Int) {
            vals[i] = Math.min(vals[2 * i], vals[2 * i + 1])
        }

        fun min(l: Int, r: Int): Long {
            var l = l
            var r = r
            var min = I
            if (l >= r) return min
            l += H
            r += H
            while (l < r) {
                if (l and 1 == 1) min = Math.min(min, vals[l++])
                if (r and 1 == 1) min = Math.min(min, vals[--r])
                l = l ushr 1
                r = r ushr 1
            }
            return min
        }

        fun firstle(l: Int, v: Long): Int {
            if (l >= H) return -1
            var cur = H + l
            while (true) {
                if (vals[cur] <= v) {
                    if (cur >= H) return cur - H
                    cur = 2 * cur
                } else {
                    cur++
                    if (cur and cur - 1 == 0) return -1
                    if (cur and 1 == 0) cur = cur ushr 1
                }
            }
        }

        fun lastle(l: Int, v: Long): Int {
            if (l < 0) return -1
            var cur = H + l
            while (true) {
                if (vals[cur] <= v) {
                    if (cur >= H) return cur - H
                    cur = 2 * cur + 1
                } else {
                    if (cur and cur - 1 == 0) return -1
                    cur--
                    if (cur and 1 == 1) cur = cur ushr 1
                }
            }
        }

        companion object {
            const val I = Long.MAX_VALUE / 2
        }

        init {
            M = Integer.highestOneBit(Math.max(N - 1, 1)) shl 2
            H = M ushr 1
            vals = LongArray(M)
            Arrays.fill(vals, 0, M, I)
        }
    }


    val out = PrintWriter(System.out)

    fun run() {
        tr(measureTimeMillis {
            solve()
            out.flush()
        })
    }

    fun nline() = readLine()!!
    fun ni() = nline().toInt()
    fun nl() = nline().toLong()
    fun nd() = nline().toDouble()
    fun nas() = nline().split(" ")
    fun na() = nas().map { it.toInt() }
    fun nal() = nas().map { it.toLong() }

    fun tr(vararg x: Any) = System.err.println(Arrays.deepToString(x))
}

// TODO
fun main() = G2().run()