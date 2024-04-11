//package f

import java.io.PrintWriter
import java.util.*

fun solve() {
    val (n, m, k) = na()
    var a = na()
    a = a.sorted()
//    tr(a)

    var cum = LongArray(n+1)
    for(i in 0..n-1){
        cum[i+1] = cum[i] + a[i]
    }

    var ans:Long  = 1000000000000000009L
    for(i in 0..n-m){
        var low = i
        var high = i+(m-1)/2+1
        while(high - low > 1){
            val h = (high+low)/2
            val up = a[h].toLong()*(h-i) - (cum[h] - cum[i])
            if(up <= k){
                low = h
            }else{
                high = h
            }
        }
        val h = low
        val up = a[h].toLong()*(h-i) - (cum[h] - cum[i])
        val lv: Long = Math.min(a[i+(m-1)/2].toLong(), a[h].toLong() + (k-up)/(h-i+1))

        val tot = lv*(h-i+1) - (cum[h+1] - cum[i]) + (cum[i+m] - cum[h+1]) - lv*((i+m-1)-(h+1)+1)
//        tr(listOf(i, tot))
        ans = Math.min(ans, tot)
    }
    out.println(ans)
}

fun solve2()
{

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