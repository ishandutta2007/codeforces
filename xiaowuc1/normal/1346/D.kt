import java.io.*
import java.util.*

    /*
reminders:
arrays of objects are problematic, prefer ArrayList instead
global things must be initialized to something (explicit null)
	*/
    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    fun main(args: Array<String>) {
        br = BufferedReader(InputStreamReader(System.`in`))
        pw = PrintWriter(BufferedWriter(OutputStreamWriter(System.out)))
        var t = readInt()
        while (t-- > 0) {
            solve()
        }
        exitImmediately()
    }

    @Throws(IOException::class)
    fun solve() {
        val n = readInt()
        var m = readInt()
        val `val` = IntArray(n)
        Arrays.fill(`val`, -1)
        val edges = ArrayList<Edge>()
        while (m-- > 0) {
            val a = readInt() - 1
            val b = readInt() - 1
            val w = readInt()
            edges.add(Edge(a, b, w))
        }
        Collections.sort(edges, EdgeCmp())
        for (out in edges) {
            if (`val`[out.a] > 0 && `val`[out.b] > 0 && `val`[out.a] != out.w && `val`[out.b] != out.w) {
                pw!!.println("NO")
                return
            }
            if (`val`[out.a] < 0) `val`[out.a] = out.w
            if (`val`[out.b] < 0) `val`[out.b] = out.w
        }
        pw!!.println("YES")
        for (i in 0 until n) {
            pw!!.print(`val`[i].toString() + " ")
        }
        pw!!.println()
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

    internal class EdgeCmp : Comparator<Edge> {
        override fun compare(a: Edge, b: Edge): Int {
            return b.w - a.w
        }
    }

    internal class Edge(var a: Int, var b: Int, var w: Int)