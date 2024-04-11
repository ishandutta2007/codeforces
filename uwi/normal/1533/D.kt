import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class D {
    fun solve() {
        var (n,m) = na()
        var map = HashMap<String, Int>()
        repeat(n){
            var s = nline()
            map.merge(s, 1, Int::plus)
        }

        var q = ni()
        repeat(q){
            var s = nline()
            var set = HashSet<String>()
            for(i in 0 until m+1){
                var temp = s.substring(0, i) + s.substring(i+1)
                set.add(temp)
            }
            var ans = 0
            for(u in set){
                ans += map.getOrDefault(u, 0);
            }
            out.println(ans)
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
fun main() = D().run()