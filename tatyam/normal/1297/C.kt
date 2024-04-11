import java.io.PrintWriter
import java.util.*
import kotlin.math.*
const val INF = 0x3fffffff

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)


    val t = sc.nextInt()
    for (i_ in 0 until t) {
        val n = sc.nextInt()
        val a = Array(n){
            sc.nextInt()
        }
        var pmin = INF
        var mindex = 0
        var nmax = -INF
        var maxdex = 0
        var ans = 0
        var s = Array(n){ '0' }
        for (i in 0 until n) {
            val A = a[i]
            when {
                A > 0 -> {
                    if(pmin > A){
                        pmin = A
                        mindex = i
                    }
                    ans += A
                    s[i] = '1'
                }
                A == 0 -> {
                    s[i] = '1'
                }
                A < 0 -> {
                    if(nmax < A){
                        nmax = A
                        maxdex = i
                    }
                }
            }
        }
        if (pmin < -nmax) {
            s[mindex] = '0'
            ans -= pmin
        }
        else {
            s[maxdex] = '1'
            ans += nmax
        }
        pw.println(ans)
        for (i in s) pw.print(i)
        pw.println()
    }

    pw.flush()
}