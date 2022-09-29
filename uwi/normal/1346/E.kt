import java.io.PrintWriter
import java.util.*

fun solve() {
    val (n, m, k) = na()
    var es: MutableList<IntArray> = mutableListOf()
    for(j in 1..m){
        val (f, q) = na()
        es.add(intArrayOf(f-1, q-1))
    }

    var h = IntArray(n)
    for(i in 0..n-1){
        h[i] = i
    }

    var ves: MutableList<MutableList<IntArray>> = mutableListOf()
    for(i in 0..n+2*m-1){
        ves.add(mutableListOf())
    }

    var gen = n
    for(e in es.reversed()){
        ves[gen].add(intArrayOf(h[e[0]], 0))
        ves[gen+1].add(intArrayOf(h[e[1]], 0))
        ves[gen].add(intArrayOf(gen+1, 1))
        ves[gen+1].add(intArrayOf(gen, 1))
        h[e[0]] = gen+1
        h[e[1]] = gen
        gen += 2
    }

    var ds = IntArray(n+2*m)
    Arrays.fill(ds, 99999999)
    ds[h[k-1]] = 0
    var q: ArrayDeque<Int> = ArrayDeque<Int>()
    q.add(h[k-1])
    while(q.isNotEmpty()){
        val cur = q.pollFirst()
        for(e in ves[cur]){
            if(e[1] == 1) {
                if (ds[e[0]] > ds[cur] + 1) {
                    ds[e[0]] = ds[cur] + 1
                    q.addLast(e[0])
                }
            }else{
                if (ds[e[0]] > ds[cur]) {
                    ds[e[0]] = ds[cur]
                    q.addFirst(e[0])
                }
            }
        }
    }
    for(i in 0..n-1){
        val v = ds[i]
        out.print(if(v <= 9999999) v else -1)
        out.print(" ")
    }
    out.println()
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