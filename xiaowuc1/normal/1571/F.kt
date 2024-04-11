import java.io.*
import java.util.*
import kotlin.collections.HashSet

    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    /*
reminders:
delete JVMStatic
to use arrays, make sure to !! after them
also .length -> .size
arrays are bad, use ArrayList instead
global things must be initialized to something (explicit null)
delete the Kotlin.throws
sort with inline comparators, you may need to non-null
do not implements Comparable 
	 */
    @Throws(IOException::class)
    fun main(args: Array<String>) {
        br = BufferedReader(InputStreamReader(System.`in`))
        pw = PrintWriter(BufferedWriter(OutputStreamWriter(System.out)))
        solve()
        exitImmediately()
    }

    @Throws(IOException::class)
    fun solve() {
        rsolve()
    }

    @Throws(IOException::class)
    fun rsolve() {
        val n = readInt()
        var m = readInt()
        val ret = IntArray(n)
        val twos = ArrayList<State>()
        var total = 0
        for (i in 0 until n) {
            val amt = readInt()
            val delta = readInt()
            if (delta == 1) {
                if (amt > m) die()
                ret[i] = m - amt + 1
                m -= amt
                continue
            }
            total += amt
            twos.add(State(amt, i))
        }
        val poss = BooleanArray(m + 1)
        val parentidx = IntArray(m + 1) // IN TWOS ARRAYLIST
        poss[0] = true
        for (i in twos.indices) {
            for (j in m downTo twos[i].num) {
                if (!poss[j] && poss[j - twos[i].num]) {
                    poss[j] = true
                    parentidx[j] = i
                }
            }
        }
        val lhs = m / 2
        val rhs = m - lhs
        var dppartition = -1
        for (a in 0..rhs) {
            if (poss[a] && total - a <= lhs) {
                dppartition = a
            }
        }
        if (dppartition < 0) {
            die()
        }
        val good: MutableSet<Int> = HashSet()
        while (dppartition > 0) {
            good.add(twos[parentidx[dppartition]].index)
            dppartition -= twos[parentidx[dppartition]].num
        }
        var lhsret = 1
        var rhsret = 2
        val used: MutableSet<Int> = HashSet()
        for (out in twos) {
            if (good.contains(out.index)) {
                ret[out.index] = lhsret
                for (a in 0 until out.num) used.add(lhsret + 2 * a)
                lhsret += 2 * out.num
            } else {
                ret[out.index] = rhsret
                for (a in 0 until out.num) used.add(rhsret + 2 * a)
                rhsret += 2 * out.num
            }
        }
        for (i in ret.indices) {
            pw!!.print(ret[i])
            if (i < ret.size - 1) pw!!.print(' ') else pw!!.println()
        }
    }

    fun die() {
        pw!!.println(-1)
        exitImmediately()
    }

    fun exitImmediately() {
        pw!!.close()
        System.exit(0)
    }

    @Throws(IOException::class)
    fun readInt(): Int {
        return readToken().toInt()
    }

    @Throws(IOException::class)
    fun readLong(): Long {
        return readToken().toLong()
    }

    @Throws(IOException::class)
    fun readDouble(): Double {
        return readToken().toDouble()
    }

    @Throws(IOException::class)
    fun readLine(): String? {
        val s = br!!.readLine()
        if (s == null) exitImmediately()
        st = null
        return s
    }

    @Throws(IOException::class)
    fun readToken(): String {
        while (st == null || !st!!.hasMoreTokens()) {
            st = StringTokenizer(readLine()!!.trim { it <= ' ' })
        }
        return st!!.nextToken()
    }

    internal class State(var num: Int, var index: Int)