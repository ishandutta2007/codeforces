//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class E {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var n = ni()
        var a = na()
        var aa = IntArray(n)
        for(i in 0 until n){
            aa[i] = a[i]-1
        }

        var b = makeBuckets(aa, n)
        var ls = IntArray(n)

        var dep = IntArray(n)
        dep[0] = -n
        var mx = 1
        var ans = 1
        for(i in 0 until n){
            if(b[aa[i]]!!.size == 2 && b[aa[i]]!![0] == i){
                var w = b[aa[i]]!![1]
                var ind = Arrays.binarySearch(dep, 0, mx, -w)
                assert(ind < 0)
                ind = -ind-2
                dep[ind+1] = -w
                ls[i] = ind+1
                ans = kotlin.math.max(ans, (ind+1)*2)
                if(b[aa[i]]!![0]+1 < b[aa[i]]!![1]){
                    ans = kotlin.math.max(ans, (ind+1)*2+1)
                }
                if(ind+1 == mx)mx++
            }
        }

        out.println(ans)
    }


    fun makeBuckets(a: IntArray, sup: Int): Array<IntArray?> {
        val n = a.size
        val bucket = arrayOfNulls<IntArray>(sup + 1)
        val bp = IntArray(sup + 1)
        for (i in 0 until n) bp[a[i]]++
        for (i in 0..sup) bucket[i] = IntArray(bp[i])
        for (i in n - 1 downTo 0) bucket[a[i]]!![--bp[a[i]]] = i
        return bucket
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
fun main() = E().run()