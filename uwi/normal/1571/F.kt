//package kh8
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class F {
    fun solve() {
        var (n, m) = na()
        var kts = mutableListOf<IntArray>()
        for(i in 0..n-1){
            kts.add(na().toIntArray())
        }

        var ret = IntArray(n)
        var day = m
        for(i in 0..n-1){
            if(kts[i][1] == 1){
                day -= kts[i][0]
                ret[i] = day + 1
            }
        }
        if(day < 0){
            out.println(-1)
            return
        }
        var e = (day+1)/2
        var s = 0
        for(kt in kts){
            if(kt[1] == 2){
                s += kt[0]
            }
        }
        if(s > day){
            out.println(-1)
            return
        }
        var dp = mutableListOf<BooleanArray>()
        dp.add(BooleanArray(e+1))
        dp[0][0] = true
        var ids = IntArray(n)
        for(j in 0..n-1){
            var kt = kts[j]
            if(kt[1] == 2) {
                dp.add(BooleanArray(e + 1))
                var p = dp.size - 1
                ids[p-1] = j
                for (i in 0..e-kt[0]) {
                    dp[p][i+kt[0]] = dp[p][i+kt[0]] || dp[p-1][i]
                }
                for (i in 0..e) {
                    dp[p][i] = dp[p][i] || dp[p-1][i]
                }
            }
        }
        for(ind in e downTo 0){
            if(dp[dp.size-1][ind]){
                if(s-ind > day-e){
                    out.println(-1)
                    return
                }
                var v = ind
                var td = 1
                for(h in dp.size-1 downTo 1){
                    if(!dp[h-1][v]){
                        var tid = ids[h-1]
                        v -= kts[tid][0]
                        ret[tid] = td
                        td += 2 * kts[tid][0]
                    }
                }

                td = 2
                for(i in 0..n-1){
                    if(ret[i] == 0){
                        ret[i] = td
                        td += 2*kts[i][0]
                    }
                    out.print(ret[i])
                    out.print(" ")
                }
                out.println()

                break
            }
        }
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