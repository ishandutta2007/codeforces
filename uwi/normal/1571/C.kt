//package kh8
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class C {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var n = ni()
        var mxx = 9999999
        var mii = 0
        for(i in 0..n-1) {
            var (s, t, rs) = nas()
            var r = rs.toInt()
            var k = t.length-1
            var mx = 0
            for(j in s.length-1 downTo 0){
                if(k < 0)break
                if(s[j] == t[k]){
                    mx += 1
                    k -= 1
                }else{
                    break
                }
            }
            if(r == 1){
                mxx = Math.min(mxx, mx)
            }else{
                mii = Math.max(mii, mx+1)
            }
        }
//        tr(mii, mxx)
        var nu = Math.max(0, mxx-mii+1)
        out.println(nu)
        for(i in mii..mxx){
            out.print(i)
            out.print(" ")
        }
        out.println()
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
fun main() = C().run()