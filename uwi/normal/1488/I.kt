//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class J {
    fun solve() {
        var (n, m, K) = na()
        var from = IntArray(m)
        var to = IntArray(m)
        var map = HashMap<Long, Int>()
        for(i in 0 until m){
            var (x, y) = na()
            from[i] = x - 1
            to[i] = y-1
            map.put((from[i].toLong() shl 32) or to[i].toLong(), i)
            map.put((to[i].toLong() shl 32) or from[i].toLong(), i)
        }
        val g = packU(n, from, to)
        val q = ArrayDeque<Int>()
        var ds = IntArray(n)
        Arrays.fill(ds, 999999999)
        ds[0] = 0
        q.add(0)
        while(!q.isEmpty()){
            var cur = q.poll()
            for(e in g[cur]){
                if(ds[e] > ds[cur] + 1){
                    ds[e] = ds[cur] + 1
                    q.add(e)
                }
            }
        }

        var es = mutableListOf<Edge>()
        var src = n + m
        var sink = src + 1
        for(i in 0 until n){
            for(e in g[i]){
                if(ds[e] == ds[i] + 1){
                    var ind = map[i.toLong() shl 32 or e.toLong()]!!
//                    tr(ind)
                    if(ds[i] % 2 == 0){
                        es.add(Edge(src, ind, 1))
                        es.add(Edge(ind, m+i, 1))
                        es.add(Edge(ind, m+e, 1))
                    }else{
                        es.add(Edge(ind, sink, 1))
                        es.add(Edge(m+i, ind, 1))
                        es.add(Edge(m+e, ind, 1))
                    }
                }
            }
        }
        var h = compileWD(sink+1, es)
//        for(row in h){
//            for(e in row){
//                tr(e.from, e.to, e.capacity, e.cloned, e.flow)
//            }
//        }

        out.println(
                kotlin.math.min(K.toLong(), maximumFlowDinic(h, src, sink))
                )
    }

    class Edge(var from: Int, var to: Int, var capacity: Long) {
        var flow: Long = 0
        var complement: Edge? = null
        var cloned = false
    }

    fun reset(g: Array<Array<Edge>>) {
        for (row in g) {
            for (e in row) {
                e.flow = if (e.cloned) e.capacity else 0
            }
        }
    }

    val dummy = Edge(-1, -1, 0L)

    fun compileWD(n: Int, edges: MutableList<Edge>): Array<Array<Edge>> {
        // cloning
        for (i in edges.indices.reversed()) {
            val origin = edges[i]
            val clone = Edge(origin.to, origin.from, origin.capacity)
            clone.flow = origin.capacity
            clone.complement = origin
            clone.cloned = true
            origin.complement = clone
            edges.add(clone)
        }
        val p = IntArray(n)
        for (e in edges) p[e.from]++
        val g: Array<Array<Edge>> = Array(n){Array(p[it]){ dummy } }
        for (e in edges) g[e.from][--p[e.from]] = e
        return g
    }

    fun maximumFlowDinic(g: Array<Array<Edge>>, source: Int, sink: Int): Long {
        val n = g.size
        val d = IntArray(n)
        val q = IntArray(n)
        var ret: Long = 0
        while (true) {
            Arrays.fill(d, -1)
            q[0] = source
            var r = 1
            d[source] = 0
            var v = 0
            while(v < r){
                val cur = q[v]
                for (ne in g[cur]) {
                    if (d[ne.to] == -1 && ne.capacity - ne.flow > 0) {
                        q[r++] = ne.to
                        d[ne.to] = d[cur] + 1
                    }
                }
                v++
            }
            if (d[sink] == -1) break
            val sp = IntArray(n)
            for (i in 0 until n) sp[i] = g[i].size - 1
            ret += dfsDinic(d, g, sp, source, sink, Long.MAX_VALUE)
        }
        return ret
    }

    private fun dfsDinic(d: IntArray, g: Array<Array<Edge>>, sp: IntArray, cur: Int, sink: Int, min: Long): Long {
        if (cur == sink) return min
        var left = min
        for (i in sp[cur] downTo 0) {
            val ne = g[cur][i]
            if (d[ne.to] == d[cur] + 1 && ne.capacity - ne.flow > 0) {
                val fl = dfsDinic(d, g, sp, ne.to, sink, Math.min(left, ne.capacity - ne.flow))
                if (fl > 0) {
                    left -= fl
                    ne.flow += fl
                    ne.complement!!.flow -= fl
                    if (left == 0L) {
                        sp[cur] = i
                        return min
                    }
                }
            }
        }
        sp[cur] = -1
        return min - left
    }


    fun packU(n: Int, from: IntArray, to: IntArray): kotlin.Array<IntArray>{
        return packU(n, from, to, from.size)
    }
    fun packU(n: Int, from: IntArray, to: IntArray, sup: Int): kotlin.Array<IntArray>{
        val p = IntArray(n)
        for (i in 0 until sup) p[from[i]]++
        for (i in 0 until sup) p[to[i]]++
        val g = Array(n) { IntArray(p[it]) }
        for (i in 0 until sup) {
            g[from[i]][--p[from[i]]] = to[i]
            g[to[i]][--p[to[i]]] = from[i]
        }
        return g
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
fun main() = J().run()