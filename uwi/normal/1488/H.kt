//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class H {
    fun solve() {
        var (n, Q) = na()
        var a = na()
        var aa = IntArray(n-1)
        for(i in 0 until n-1)aa[i] = a[i]

        val st = SegmentTreeMatrix(aa)
        repeat(Q){
            var x = ni()-1
            st.flip(x)
            var v = IntArray(8)
            for(i in 0 until 4){
                v[i] = 1
            }
            var ret = st.apply(0, n-1, v)
            var ans = 0L
            for(v in ret){
                ans += v
            }
            out.println(ans % 998244353)
        }
    }

    class SegmentTreeMatrix(h: IntArray) {
        var M: Int
        var H: Int
        var N: Int
        var hh: IntArray
        var node: Array<Array<IntArray>>
        private fun propagate(cur: Int) {
            node[cur] = prop2(node[2 * cur], node[2 * cur + 1], node[cur])
        }

        private fun prop2(L: Array<IntArray>, R: Array<IntArray>, C: Array<IntArray>): Array<IntArray> {
            return mul(L, R, C)
        }

//        private fun prop1(L: Array<IntArray?>, C: Array<IntArray?>?): Array<IntArray?> {
//            var C = C
//            if (C == null) {
////			C = L; // read only
//                C = arrayOfNulls(S)
//                for (i in 0 until S) {
//                    C[i] = Arrays.copyOf(L[i], S)
//                }
//            } else {
//                for (i in 0 until S) {
//                    C[i] = Arrays.copyOf(L[i], S)
//                }
//            }
//            return C
//        }

        fun flip(pos: Int) {
            hh[pos] = 1 - hh[pos]

            for(j in 0..7) {
                for (k in 0..7) {
                    node[H + pos][j][k] = 0
                }
            }
            if(hh[pos] == 0){
                for(j in 0..3){
                    for(k in j..3){
                        node[H+pos][k][j] = 1
                    }
                }
                for(j in 0..3){
                    for(k in j+1..3){
                        node[H+pos][k][j+4] = 1
                    }
                }
            }else{
                for(j in 0..3){
                    for(k in 0..j-1){
                        node[H+pos][k+4][j] = 1
                    }
                }
                for(j in 0..3){
                    for(k in 0..j){
                        node[H+pos][k+4][j+4] = 1
                    }
                }
            }

            var i = H + pos ushr 1
            while (i >= 1) {
                propagate(i)
                i = i ushr 1
            }
        }

        fun apply(l: Int, r: Int, v: IntArray): IntArray {
            return apply(l, r, 0, H, 1, v)
        }

        protected fun apply(l: Int, r: Int, cl: Int, cr: Int, cur: Int, v: IntArray): IntArray {
            var v = v
            return if (l <= cl && cr <= r) {
                mul(node[cur], v)
            } else {
                val mid = cl + cr ushr 1
                if (mid < r && l < cr) {
                    v = apply(l, r, mid, cr, 2 * cur + 1, v)
                }
                if (cl < r && l < mid) {
                    v = apply(l, r, cl, mid, 2 * cur, v)
                }
                v
            }
        }

        companion object {
            val mod = 998244353
            val BIG = 8L * mod * mod
            val S = 8
            fun mul(A: Array<IntArray>, v: IntArray): IntArray {
                val m = A.size
                val n = v.size
                val w = IntArray(m)
                for (i in 0 until m) {
                    var sum: Long = 0
                    for (k in 0 until n) {
                        sum += A[i][k].toLong() * v[k]
                        if (sum >= BIG) sum -= BIG
                    }
                    w[i] = (sum % mod).toInt()
                }
                return w
            }

            fun mul(A: Array<IntArray>, B: Array<IntArray>, C: Array<IntArray>): Array<IntArray> {
                assert(A[0].size == B.size)
                val m = A.size
                val n: Int = A[0].size
                val o: Int = B[0].size
                for (i in 0 until m) {
                    for (j in 0 until o) {
                        var sum: Long = 0
                        for (k in 0 until n) {
                            sum += A[i][k].toLong() * B[k][j]
                            if (sum >= BIG) sum -= BIG
                        }
                        sum %= mod.toLong()
                        C[i][j] = sum.toInt()
                    }
                }
                return C
            }
        }

        init {
            hh = h
            N = h.size
            M = Integer.highestOneBit(Math.max(N - 1, 1)) shl 2
            H = M ushr 1
            node = Array(M) { Array(S) { IntArray(S)} }
            for (i in 0 until N) {
                if(h[i] == 0){
                    for(j in 0..3){
                        for(k in j..3){
                            node[H+i][k][j] = 1
                        }
                    }
                    for(j in 0..3){
                        for(k in j+1..3){
                            node[H+i][k][j+4] = 1
                        }
                    }
                }else{
                    for(j in 0..3){
                        for(k in 0..j-1){
                            node[H+i][k+4][j] = 1
                        }
                    }
                    for(j in 0..3){
                        for(k in 0..j){
                            node[H+i][k+4][j+4] = 1
                        }
                    }
                }
            }
            for (i in H - 1 downTo 1) propagate(i)
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
fun main() = H().run()