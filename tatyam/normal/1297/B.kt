import java.io.PrintWriter
import java.util.*
import kotlin.math.*

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)


    val t = sc.nextInt()
    for (i_ in 0 until t) {
        val n = sc.nextInt()
        val a = Array(n){
            Pair(sc.nextInt(), sc.nextInt())
        }
        val b = mutableMapOf<Int, Int>()
        a.forEach { (l, r) ->
            b.putIfAbsent(l - 1, 0)
            b.putIfAbsent(l, 0)
            b.putIfAbsent(r, 0)
            b.putIfAbsent(r + 1, 0)
            b[l] = b[l]!! + 1
            b[r + 1] = b[r + 1]!! - 1
        }
        val c = b.toSortedMap().toList().toMutableList()
        for (i in 0 until c.size - 1) {
            c[i + 1] = Pair(c[i + 1].first, c[i].second + c[i + 1].second)
        }
        var flag = true
        for ((key, value) in c) if(value == 1) {
            pw.println(key)
            flag = false
            break
        }
        if (flag) pw.println(-1)
    }

    pw.flush()
}