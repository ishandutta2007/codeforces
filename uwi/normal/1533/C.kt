import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class C {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var (n,k) = na()
        var s = nline()
        var q = ArrayDeque<Int>()
        var one = 0
        for(c in s){
            one += c.toInt() - 48
            q.add(c.toInt() - 48)
        }
        var ate = 0
        while(one > 0){
            var cur = q.pollFirst()
            one -= cur
            ate++
            if(ate < n) {
                for (i in 0 until (k - 1) % (n - ate)) {
                    q.addLast(q.pollFirst())
                }
            }
        }
        out.println(ate)
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