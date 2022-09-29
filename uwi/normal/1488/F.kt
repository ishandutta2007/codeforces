//package kh6
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class F {
    fun solve() {
        var n = ni()
        var a = na()

        var qs = mutableListOf<IntArray>()

        for(i in 0 until ni()){
            var (x, y) = na()
            qs.add(intArrayOf(x-1, y-1, i))
        }

        qs.sortBy {it[1]}

        var vs = IntArray(n)
        var ps = IntArray(n)
        var ss = LongArray(n)
        var sp = 0
        var anss = LongArray(qs.size)
        var r = 0
        for(q in qs){
            while(r <= q[1]){
                while(sp > 0 && vs[sp-1] <= a[r]){
                    sp--
                }
                vs[sp] = a[r]
                ps[sp] = r
                if(sp == 0){
                    ss[sp] = a[r].toLong() * (r + 1)
                }else{
                    ss[sp] = ss[sp-1] + a[r].toLong() * (r - ps[sp-1])
                }
                sp++

                r++
            }
            var ind = Arrays.binarySearch(ps, 0, sp, q[0])
            if(ind < 0){
                ind = -ind-1
            }
            anss[q[2]] = ss[sp-1] - ss[ind] + vs[ind].toLong() * (ps[ind] - q[0] + 1)
        }

        anss.forEach{ out.print("$it ") }
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
fun main() = F().run()