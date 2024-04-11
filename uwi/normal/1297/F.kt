import java.io.PrintWriter
import java.util.*

fun solve() {
    val t = ni()
    for(i in 1..t){
        go()
    }
}

fun go()
{
    var(n,K) = na()
    var ms: MutableList<IntArray> = mutableListOf()
    for(i in 1..n){
        val(a, b) = na()
        ms.add(intArrayOf(a, b, i-1, -1))
    }
    ms.sortBy {it[0]}

    var lo = -1
    var hi = 200005
    while(hi - lo > 1){
        var h = hi+lo shr 1
        if(ok(h, ms, K)){
            hi = h
        }else{
            lo = h
        }
    }
    out.println(hi)
    ok(hi, ms, K)
    ms.sortBy {it[2]}
    for(e in ms){
        out.print(e[3])
        out.print(" ")
    }
    out.println()
}

fun ok(h: Int, ms: MutableList<IntArray>, K: Int): Boolean {
    var pq: PriorityQueue<IntArray> = PriorityQueue<IntArray>(){i1: IntArray, i2: IntArray ->
        return@PriorityQueue i1[0] - i2[0]
    }
    var prev = 0
    var p = 0
    for(e in ms){
        while(prev < e[0] && pq.isNotEmpty()){
            for(t in 0..K-1) {
                if(pq.isEmpty())break
                val f = pq.poll()
                if(f[0] < prev){
                    return false
                }
                ms[f[1]][3] = prev
            }
            prev += 1
        }

        pq.add(intArrayOf(e[1] + h, p))
        p += 1
        prev = e[0]
    }

    while(pq.isNotEmpty()){
        for(t in 0..K-1) {
            if(pq.isEmpty())break
            val f = pq.poll()
            if(f[0] < prev){
                return false
            }
            ms[f[1]][3] = prev
        }
        prev += 1
    }

    return true
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