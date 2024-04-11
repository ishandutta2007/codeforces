import java.io.PrintWriter
import java.lang.Math.min
import java.util.*

fun solve() {
    val t = ni()
    for(i in 1..t){
        go()
    }
}

fun go() {
    val n = ni()
    var a = na()
    var max = 0
    for(l in a){
        if(l >= 0){
            max += l
        }
    }
    var minp = 99999999
    var argp = -1
    for(i in 0..n-1){
        if(a[i] > 0 && a[i] < minp){
            minp = a[i]
            argp = i
        }
    }
    var maxn = -99999999
    var argn = -1
    for(i in 0..n-1){
        if(a[i] < 0 && a[i] > maxn){
            maxn = a[i]
            argn = i
        }
    }
    if(argn != -1 && -maxn < minp){
        out.println(max+maxn)
        for(i in 0..n-1){
            if(a[i] > 0 || i == argn){
                out.print(1)
            }else{
                out.print(0)
            }
        }
        out.println()
    }else{
        out.println(max-minp)
        for(i in 0..n-1){
            if(a[i] > 0 && i != argp){
                out.print(1)
            }else{
                out.print(0)
            }
        }
        out.println()
    }
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