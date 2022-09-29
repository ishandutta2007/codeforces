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
    var (n, K) = na()
    var g: MutableList<MutableList<Int>> = mutableListOf()
    for(i in 0..n-1){
        g.add(mutableListOf())
    }
    for(i in 1..n-1){
        val(x, y) = na()
        g[x-1].add(y-1)
        g[y-1].add(x-1)
    }

    if(K == 1){
        out.println("Yes")
        out.println(1)
        out.println(1)
        return
    }

    var lvs: MutableList<Int> = mutableListOf()
    var root = -1
    for(i in 0..n-1){
        if(g[i].size == 1 && lvs.size < K){
            lvs.add(i)
        }
        if(g[i].size > 1){
            root = i
        }
    }

    if(root == -1){
        out.println("Yes")
        out.println(2)
        out.println("1 2")
        return
    }

    if(lvs.size != K){
        out.println("No")
        return
    }

    var mark: IntArray = IntArray(n)
    var (par, ord, dep) = parents(g, root)
    for(e in lvs){
        var f = e
        while(f != -1 && mark[f] == 0){
            mark[f] = 1
            f = par[f]
        }
    }
    var cur = root
    while(true) {
        var mct = 0
        var med = 0
        for (e in g[cur]) {
            if (par[cur] == e) continue
            mct += mark[e]
            if (mark[e] > 0) {
                med = e
            }
        }
        if (mct == 1) {
            mark[cur] = 0
            cur = med
        }else{
            break
        }
    }
    out.println("Yes")
    var sum = 0
    for(e in mark)sum += e
    out.println(sum)
    for(i in 0..n-1){
        if(mark[i] == 1){
            out.print(i+1)
            out.print(" ")
        }
    }
    out.println()
}

fun parents(g: MutableList<MutableList<Int>>, root: Int): Array<IntArray> {
    val n = g.size
    val par = IntArray(n)
    Arrays.fill(par, -1)
    val depth = IntArray(n)
    depth[0] = 0
    var q: IntArray = IntArray(n)
    q[0] = root
    var p = 0
    var r = 1
    while (p < r) {
        val cur = q[p]
        for (nex in g[cur]) {
            if (par[cur] != nex) {
                q[r++] = nex
                par[nex] = cur
                depth[nex] = depth[cur] + 1
            }
        }
        p++
    }
    return arrayOf<IntArray>(par, q, depth)
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