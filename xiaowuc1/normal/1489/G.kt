import java.io.*
import java.util.*

    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    /*
reminders:
char[] is bad
int[] is good?
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
        val n = readInt()
        var m = readInt()
        val l = LongArray(n)
        var mini = 0
        for (i in 0 until n) {
            l[i] = readLong()
            if (l[i] < l[mini]) mini = i
        }
        val edges = ArrayList<Edge>()
        p = IntArray(n)
        for (i in 0 until n) p!![i] = i
        for (i in 0 until n) {
            edges.add(Edge(i, mini, l[i] + l[mini]))
        }
        while (m-- > 0) {
            var a = readInt()
            var b = readInt()
            val w = readLong()
            edges.add(Edge(--a, --b, w))
        }
        Collections.sort(edges) { a, b -> java.lang.Long.compare(a.w, b.w) }
        var ret: Long = 0
        for (out in edges) {
            if (merge(out.a, out.b)) ret += out.w
        }
        pw!!.println(ret)
    }

    var p: IntArray? = null
    fun find(x: Int): Int {
        return if (p!![x] == x) x else find(p!![x]).also { p!![x] = it }
    }

    fun merge(x: Int, y: Int): Boolean {
        var x = x
        var y = y
        x = find(x)
        y = find(y)
        if (x == y) return false
        p!![x] = y
        return true
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

    internal class Edge(var a: Int, var b: Int, var w: Long)