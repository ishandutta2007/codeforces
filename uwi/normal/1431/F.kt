import java.io.PrintWriter
import java.util.*

fun solve() {
    var (n, K, X) = na()
    var a = na()
    var aa = IntArray(n)
    for(i in 0..n-1){
        aa[i] = a[i]
    }
    var low = -1L
    var high = 100000000000L
    while(high - low > 1){
        var h = (low+high)/2
        if(ok(h, K, X, aa)){
            high = h
        }else{
            low = h
        }
    }
    out.println(high)
}

fun ok(h:Long, K: Int, X: Int, a: IntArray): Boolean
{
    var pq = PriorityQueue<Int>()
    var rem = 0
    var s = 0L
    for(v in a){
        s = s + v.toLong()
        pq.add(-v)
        if(s > h){
            s = s - (-pq.poll()).toLong()
            rem += 1
        }
        if(pq.size.toInt() == X){
            pq.clear()
            s = 0
        }
    }
    return rem <= K
}

val out = PrintWriter(System.out)

fun main() {
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