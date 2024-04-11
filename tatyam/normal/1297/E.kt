import java.io.PrintWriter
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*
const val INF = 0x3fffffff

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)


    val t = sc.nextInt()
    for (i_ in 0 until t) {
        val n = sc.nextInt()
        val k = sc.nextInt()
        val g = Array(n){ mutableSetOf<Int>() }
        val ans = Array(n){ true }
        for (i_ in 1 until n) {
            val a = sc.nextInt() - 1
            val b = sc.nextInt() - 1
            g[a].add(b)
            g[b].add(a)
        }
        if (k == 1) {
            pw.println("""Yes
1
1""")
            continue
        }
        val q = Stack<Int>()
        for (i in 0 until n) if(g[i].size == 1) {
            q.add(i)
        }
        if (k > q.size) {
            pw.println("No")
            continue
        }
        while (k < q.size) {
            val at = q.last()
            q.pop()
            ans[at] = false
            val p = g[at].first()
            g[p].remove(at)
            if (g[p].size == 1) q.add(p)
        }
        pw.println("Yes")
        pw.println(ans.count { it })
        for (i in 0 until n) if(ans[i]) pw.print("${i + 1} ")
        pw.println()
    }

    pw.flush()
}