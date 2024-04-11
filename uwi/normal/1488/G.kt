//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class G2 {
    fun solve() {
        var n = ni()
        var a = BooleanArray(n+1)
        var bal = IntArray(n+1)
        for(i in 1..n){
            for(j in 2..n/i){
                bal[j*i]--
            }
        }
        var ans = 0L
        var h = MinHeap(n+1)
        for(i in 1..n){
            h.add(i, bal[i])
        }
        for(k in 1..n){
            var arg = h.argmin()
            var mx = h.remove(arg)
            a[arg] = true
            ans -= mx
            var u = 1
            while(u*u <= arg){
                if(arg % u == 0){
                    if(!a[u]){
                        bal[u]++
                        h.update(u, bal[u])
                    }
                    if(!a[arg/u] && arg/u != u){
                        bal[arg/u]++
                        h.update(arg/u, bal[arg/u])
                    }
                }
                u += 1
            }
            out.print("$ans ")
        }
        out.println()
    }

    val out = PrintWriter(System.out)

    class MinHeap(m: Int) {
        var a: IntArray
        var map: IntArray
        var imap: IntArray
        var n: Int
        var pos: Int
        fun add(ind: Int, x: Int): Int {
            val ret = imap[ind]
            if (imap[ind] < 0) {
                a[pos] = x
                map[pos] = ind
                imap[ind] = pos
                pos++
                up(pos - 1)
            }
            return if (ret != -1) a[ret] else x
        }

        fun update(ind: Int, x: Int): Int {
            val ret = imap[ind]
            if (imap[ind] < 0) {
                a[pos] = x
                map[pos] = ind
                imap[ind] = pos
                pos++
                up(pos - 1)
            } else {
                val o = a[ret]
                a[ret] = x
                up(ret)
                down(ret)
                //			if(a[ret] > o){
//				up(ret);
//			}else{
//				down(ret);
//			}
            }
            return x
        }

        fun remove(ind: Int): Int {
            if (pos == 1) return INF
            if (imap[ind] == -1) return INF
            pos--
            val rem = imap[ind]
            val ret = a[rem]
            map[rem] = map[pos]
            imap[map[pos]] = rem
            imap[ind] = -1
            a[rem] = a[pos]
            a[pos] = INF
            map[pos] = -1
            up(rem)
            down(rem)
            return ret
        }

        fun min(): Int {
            return a[1]
        }

        fun argmin(): Int {
            return map[1]
        }

        fun size(): Int {
            return pos - 1
        }

        private fun up(cur: Int) {
            var c = cur
            var p = c ushr 1
            while (p >= 1 && a[p] > a[c]) {
                val d = a[p]
                a[p] = a[c]
                a[c] = d
                var e = imap[map[p]]
                imap[map[p]] = imap[map[c]]
                imap[map[c]] = e
                e = map[p]
                map[p] = map[c]
                map[c] = e
                c = c ushr 1
                p = p ushr 1
            }
        }

        private fun down(cur: Int) {
            var c = cur
            while (2 * c < pos) {
                val b = if (a[2 * c] < a[2 * c + 1]) 2 * c else 2 * c + 1
                if (a[b] < a[c]) {
                    val d = a[c]
                    a[c] = a[b]
                    a[b] = d
                    var e = imap[map[c]]
                    imap[map[c]] = imap[map[b]]
                    imap[map[b]] = e
                    e = map[c]
                    map[c] = map[b]
                    map[b] = e
                    c = b
                } else {
                    break
                }
            }
        }

        companion object {
            var INF = Int.MAX_VALUE
        }

        init {
            n = m + 2
            a = IntArray(n)
            map = IntArray(n)
            imap = IntArray(n)
            Arrays.fill(a, INF)
            Arrays.fill(map, -1)
            Arrays.fill(imap, -1)
            pos = 1
        }
    }


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