import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class H2 {
    fun solve() {
        val (n, m) = na()
        val mp = mutableListOf<String>()
        repeat(n){
            mp.add(nline())
        }

//        var n = 800
//        var m = 800
//        var mp = mutableListOf<String>()
//        var gen = Random()
//        repeat(n){
//            var s = CharArray(m)
//            for(i in 0 until m){
//                s[i] = (gen.nextInt(5) + 65).toChar()
//            }
//            mp.add(String(s))
//        }

        var ss = LongArray(32)

        for(q in 0 until 32){
            val h = IntArray(m)
            var s = 0L
            for(i in 0 until n){
                for(j in 0 until m){
                    val k = mp[i][j].toInt()-65
                    if(((q shr k) and 1) == 0){
                        h[j]++
                    }else{
                        h[j] = 0
                    }
                }
                var inds = IntArray(m)
                var hs = IntArray(m)
                var sp = 0
                for(j in 0 until m){
                    var prex = j
                    while(sp > 0 && hs[sp-1] >= h[j]){
                        var prevh = if(sp-2 >= 0) Math.max(h[j], hs[sp-2]) else h[j]
                        s += (hs[sp-1]-prevh).toLong() * (j - inds[sp-1]) * (j - inds[sp-1] + 1) / 2
                        prex = inds[sp-1]
                        sp--
                    }
                    hs[sp] = h[j]
                    inds[sp] = prex
                    sp++
                }
                while(sp > 0){
                    var prevh = if(sp-2 >= 0) hs[sp-2] else 0
                    s += (hs[sp-1]-prevh).toLong() * (m - inds[sp-1]) * (m - inds[sp-1] + 1) / 2
                    sp--
                }
            }
            ss[q] = s
        }

        var temp = LongArray(32)
        for(i in 0 until 32){
            for(j in 0 until i+1){
                if((i and j) == j){
                    if(Integer.bitCount(j) % 2 == 0) {
                        temp[i] += ss[j]
                    }else{
                        temp[i] -= ss[j]
                    }
                }
            }
        }
        for(i in 31 downTo 0){
            for(j in i+1 until 32){
                if((j and i) == i){
                    temp[i] -= temp[j]
                }
            }
        }

        var ans = LongArray(6)
        for(i in 0 until 32){
            ans[Integer.bitCount(i)] += temp[i]
        }

        for(i in 1..5){
            out.print(ans[i])
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
fun main() = H2().run()