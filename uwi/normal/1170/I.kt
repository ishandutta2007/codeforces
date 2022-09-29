//package i

import java.io.PrintWriter
import java.util.*
import java.util.Arrays.binarySearch

var xs: IntArray = IntArray(1)
val st: SegmentTreeRSQ = SegmentTreeRSQ(410000)
//val st: SegmentTreeRSQ = SegmentTreeRSQ(7)

fun solve() {
    var n = ni()
    val rs: MutableList<IntArray> = mutableListOf()
    for(i in 1..n){
        val (x, y) = na()
        rs.add(intArrayOf(x, y))
    }
    xs = IntArray(2*n)
    var p = 0
    for(r in rs){
        xs[p++] = r[0]
        xs[p++] = r[1]
    }
    xs.sort()
    var q = 0
    for(i in 0..p-1){
        if(i == 0 || xs[i] != xs[i-1]){
            xs[q++] = xs[i]
        }
    }
    xs = Arrays.copyOf(xs, q)

    rs.sortBy { it[0] }
    var reach = -1
    var cur: MutableList<IntArray> = mutableListOf()
    var ans: Long = 1
    for(r in rs){
        if(r[0] > reach){
            ans = ans * go(cur) % mod
            cur.clear()
//            tr(listOf("ans", ans))
        }
        reach = Math.max(reach, r[1])
        cur.add(r)
    }
//    tr(listOf("ans", ans))
    ans = ans * go(cur) % mod
    out.println(ans)
}

fun go(cur: MutableList<IntArray>): Long{
    if(cur.size == 0){
        return 1L
    }
    st.mul(0, 405000, 0)
    val fi = binarySearch(xs, cur[0][0])
    var last = 0
//    tr(fi)
    st.add(fi, 1)
//    tr(cur.size)
//    tr(Arrays.toString(st.st))
//    tr(Arrays.toString(st.muls))
    for(r in cur){
        val rl = binarySearch(xs, r[0])
        val rr = binarySearch(xs, r[1])
        val s = st.sum(rl, rr+1)
//        tr(listOf(rl, rr, s))
        st.add(rr, s)
        st.mul(rr+1, 405000, 2)
        last = Math.max(last, rr)
//        tr(Arrays.toString(st.st))
//        tr(Arrays.toString(st.muls))
    }

    var ret = st.sum(last, last+1)
    if(fi == last){
        ret = (ret + mod - 1) % mod
    }
    return ret
}

val mod = 998244353

class SegmentTreeRSQ {
    var M: Int = 0
    var H: Int = 0
    var N: Int = 0
    var st: LongArray
    var muls: LongArray
    val mod = 998244353

    constructor(n: Int) {
        N = n
        M = Integer.highestOneBit(Math.max(N - 1, 1)) shl 2
        H = M.ushr(1)
        st = LongArray(M)
        muls = LongArray(H)
    }

    constructor(a: IntArray) {
        N = a.size
        M = Integer.highestOneBit(Math.max(N - 1, 1)) shl 2
        H = M.ushr(1)
        st = LongArray(M)
        muls = LongArray(H)
        for (i in 0 until N) {
            st[H + i] = a[i].toLong()
        }
        for (i in (M shr 1) - 1 downTo 1) {
            propagate(i)
        }
    }

    fun add(pos: Int, v: Long) {
        for(x in 20 downTo 1){
            val ind = H+pos ushr x
            if(ind >= 1){
                fall(ind)
            }
        }

        st[H+pos] += v
        if(st[H+pos] >= mod)st[H+pos] = st[H+pos] - mod
        var i = H+pos ushr 1
        while (i >= 1) {
            propagate(i)
            i = i ushr 1
        }
    }

    private fun propagate(i: Int) {
//        val count = H / Integer.highestOneBit(i)
        st[i] = (st[2 * i] + st[2 * i + 1]) * muls[i] % mod
    }

    fun mul(l: Int, r: Int, v: Int) {
        if (l < r) mul(l, r, v, 0, H, 1)
    }

    private fun fall(cur: Int)
    {
        if(2*cur >= H){
            st[2*cur] = st[2*cur] * muls[cur] % mod
            st[2*cur+1] = st[2*cur+1] * muls[cur] % mod
        }else{
            muls[2*cur] = muls[2*cur] * muls[cur] % mod
            muls[2*cur+1] = muls[2*cur+1] * muls[cur] % mod
            propagate(2*cur)
            propagate(2*cur+1)
        }
        muls[cur] = 1
    }

    private fun mul(l: Int, r: Int, v: Int, cl: Int, cr: Int, cur: Int) {
        if (cur >= H) {
            st[cur] = st[cur] * v.toLong() % mod
        } else if (l <= cl && cr <= r) {
            muls[cur] = muls[cur] * v.toLong() % mod
            propagate(cur)
        } else {
            fall(cur)
            val mid = (cl + cr).ushr(1)
            if (cl < r && l < mid) {
                mul(l, r, v, cl, mid, 2 * cur)
            }
            if (mid < r && l < cr) {
                mul(l, r, v, mid, cr, 2 * cur + 1)
            }
            propagate(cur)
        }
    }

    fun sum(l: Int, r: Int): Long {
        return sum(l, r, 0, H, 1)
    }

    private fun sum(l: Int, r: Int, cl: Int, cr: Int, cur: Int): Long {
        if (l <= cl && cr <= r) {
            return st[cur]
        } else {
            val mid = (cl + cr).ushr(1)
            var ret = 0L
            if (cl < r && l < mid) {
                ret += sum(l, r, cl, mid, 2 * cur)
            }
            if (mid < r && l < cr) {
                ret += sum(l, r, mid, cr, 2 * cur + 1)
            }
            return ret * muls[cur] % mod
        }
    }
}

val out = PrintWriter(System.out)

fun main(args: Array<String>) {
    solve()
    out.flush()
}

fun nline() = readLine()!!
fun ni() = nline().toInt()
fun nl() = nline().toLong()
fun nd() = nline().toDouble()
fun nas() = nline().split(" ")
fun na() = nas().map { it.toInt() }
fun nal() = nas().map { it.toLong() }

fun tr(x: Any) = System.err.println(x)
fun tr(x: IntArray) = System.err.println(Arrays.toString(x))
fun tr(x: Array<Any>) = System.err.println(Arrays.deepToString(x))