//package kh8
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class H {
    fun solve() {
        var (n, a, b) = na()
        val mod = 998244353
        var co = mutableListOf<IntArray>()
        for(i in 0..n-1){
            co.add(na().toIntArray())
        }

        var xs = BooleanArray(101)
        var ys = BooleanArray(101)
        for(c in co){
            xs[c[0]] = true
            ys[c[1]] = true
        }

        var nx = 0
        var ny = 0
        for(i in 0..100){
            if(xs[i])nx++
            if(ys[i])ny++
        }

        var psr = LongArray(202)
        var psl = LongArray(202)
        Arrays.fill(psr, 1L)
        Arrays.fill(psl, 1L)

        val im = invl(1000000, mod.toLong())
        for(c in co){
            var le = c[1]-c[0]+100
            psr[le] = psr[le] * (1000000-c[2]) % mod * im % mod
            var le2 = c[1]+c[0]
            psl[le2] = psl[le2] * (1000000-c[2]) % mod * im % mod
        }
//        tr(psr, psl)

        var ans = ((nx+1)*(ny+1)).toLong()
//        tr(ans)
        for(i in 0..200){
            var ct = 1L
            for(j in 0..a){
                if(xs[j]) {
                    // y-j+100 = i
                    var y = j - 100 + i
                    if(y > 0 && y < b){
                        ct++
                        if(ys[y]){
                            ct--
                        }
                    }
                }
            }
            for(j in 0..b){
                if(ys[j]) {
                    // j-x+100= i
                    var x = j + 100 - i
                    if(x > 0 && x < a){
                        ct++
                    }
                }
            }
            ans += ct*(mod+1-psr[i])
            ans %= mod
        }

//        tr(ans)
        for(i in 0..200){
            var ct = 1L
            for(j in 0..a){
                if(xs[j]) {
                    var y = i-j
                    if(y > 0 && y < b){
                        ct++
                        if(ys[y]){
                            ct--
                        }
                    }
                }
            }
            for(j in 0..b){
                if(ys[j]) {
                    var x = i-j
                    if(x > 0 && x < a){
                        ct++
                    }
                }
            }
            ans += ct*(mod+1-psl[i])
            ans %= mod
        }

        for(i in 0..200){
            for(j in 0..200){
                // y-x+100=i
                // y+x=j
                // y = (i-100+j)/2
                // x = (j-(i-100))/2
                var y2 = i-100+j
                var x2 = j-(i-100)
                if(0 < x2 && x2 < 2*a && 0 < y2 && y2 < 2*b){
                    if(x2 % 2 == 0 && y2 % 2 == 0 && (xs[x2/2] || ys[y2/2])){
                        continue
                    }
                    ans += (mod+1-psr[i])*(mod+1-psl[j])
                    ans %= mod
                }
            }
        }
        out.println(ans)

    }

    fun invl(a: Long, mod: Long): Long {
        var a = a
        var b = mod
        var p: Long = 1
        var q: Long = 0
        while (b > 0) {
            val c = a / b
            var d: Long
            d = a
            a = b
            b = d % b
            d = p
            p = q
            q = d - c * q
        }
        return if (p < 0) p + mod else p
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
fun main() = H().run()