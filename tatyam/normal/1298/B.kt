import java.io.PrintWriter
import java.util.*

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)
    val n = sc.nextInt()
    val a = IntArray(n){ sc.nextInt() }
    val s = mutableSetOf<Int>()
    val ans = mutableListOf<Int>()
    for (i in n - 1 downTo 0) if(s.add(a[i])) ans += a[i]
    pw.println(ans.size)
    ans.reverse()
    for (i in ans) pw.print("$i ")
    pw.flush()
}