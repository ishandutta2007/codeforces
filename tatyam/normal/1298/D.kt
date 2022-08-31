import java.io.PrintWriter
import java.util.*
import kotlin.math.*

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)

    val n = sc.nextInt()
    val w = sc.nextInt()
    val a = IntArray(n){ sc.nextInt() }
    val b = IntArray(n + 1)
    for (i in 0 until n) {
        b[i + 1] = a[i] + b[i]
    }
    val mn = b.min()!!
    val mx = b.max()!!
    val ans = w - mx + mn + 1
    pw.println(max(0, ans))

    pw.flush()
}