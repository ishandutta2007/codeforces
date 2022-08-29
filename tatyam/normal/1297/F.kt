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
        val m = sc.nextInt()
        val a = Array(n){
            Triple(sc.nextInt(), sc.nextInt(), it)
        }
        a.sortBy { it.first }
        val ans = IntArray(n)
        var d = 0
        val s = Stack<Triple<Int, Int, Int>>()
        for (i in a.reversed()) s.push(i)
        val q = PriorityQueue<Pair<Int, Int>> { a, b -> a.first - b.first }
        var at = 0
        while (s.isNotEmpty() || q.isNotEmpty()) {
            if (q.isEmpty()) {
                at = s.peek().first
            }
            while (s.isNotEmpty() && s.peek().first == at) {
                q.add(s.peek().second to s.peek().third)
                s.pop()
            }
            for (i_ in 0 until m) {
                if (q.isEmpty()) break
                val (end, i) = q.poll()
                ans[i] = at
                if (d < at - end) d = at - end
            }
            at++
        }
        pw.println(d)
        for (i in ans) pw.print("$i ")
        pw.println()
    }

    pw.flush()
}