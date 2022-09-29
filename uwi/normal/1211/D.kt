import java.io.PrintWriter
import java.util.*

fun solve() {
    val (n, a, b, K) = na()
    val rs = na()
    var se: MutableMap<Int, Int> = mutableMapOf()
    for(r in rs){
        if(!se.containsKey(r)){
            se[r] = 1
        }else{
            se[r] = se[r]!! + 1
        }
    }

    var ans = 0
    for(r in se.keys){
        if((r%K != 0 || !se.containsKey(r/K)) && se.containsKey(r*K)){
            var m: MutableList<Int> = mutableListOf()
            var cur = r
            while(se.containsKey(cur)){
                m.add(se[cur]!!)
                cur *= K
            }

            var dp = IntArray(m[0]+1)
            for(i in 1..m.size-1){
                var u = m[i]
                var ndp = IntArray(u+1)
                for(i in 0..u){
                    if(i % b == 0){
                        var j = i/b*a
                        if(j < dp.size){
                            ndp[u-i] = dp[j] + i/b
                        }
                    }
                }
                for(i in u-1 downTo 0){
                    ndp[i] = Math.max(ndp[i], ndp[i+1])
                }
                dp = ndp
//                tr(dp)
            }
            ans += dp.max()!!
        }
    }
    out.println(ans)
}

val out = PrintWriter(System.out)

fun main(args: Array<String>) {
    solve()
    out.flush()
}

fun nline() = readLine()!!
fun ni() = nline().toInt()
fun nl() = nline().toLong()
fun nd() = nline().toDouble()
fun nas() = nline().split(" ")
fun na() = nas().map { it.toInt() }
fun nal() = nas().map { it.toLong() }

fun tr(x: Any) = System.err.println(x)
fun tr(x: IntArray) = System.err.println(Arrays.toString(x))
fun tr(x: Array<Any>) = System.err.println(Arrays.deepToString(x))