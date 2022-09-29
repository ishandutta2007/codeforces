import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class F {
    fun solve() {
        var s = nline()
        var n = s.length
        var f0 = IntArray(n+1)
        var f1 = IntArray(n+1)
        for(i in 0 until n){
            if(s[i] == '0'){
                f0[i+1] = f0[i] + 1
                f1[i+1] = f1[i]
            }else{
                f0[i+1] = f0[i]
                f1[i+1] = f1[i] + 1
            }
        }
        for(k in 1..n){
            var cur = 0
            var ans = 0
            while(cur < n){
                cur = Math.max(
                        lowerBound(f0, f0[cur] + k + 1) - 1,
                        lowerBound(f1, f1[cur] + k + 1) - 1
                )
                ans++
            }
            out.print(ans)
            out.print(" ")
        }
        out.println()
    }

    fun lowerBound(a: IntArray, v: Int): Int {
        return lowerBound(a, 0, a.size, v)
    }

    fun lowerBound(a: IntArray, l: Int, r: Int, v: Int): Int {
        require(!(l > r || l < 0 || r > a.size))
        var low = l - 1
        var high = r
        while (high - low > 1) {
            val h = high + low ushr 1
            if (a[h] >= v) {
                high = h
            } else {
                low = h
            }
        }
        return high
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
fun main() = F().run()