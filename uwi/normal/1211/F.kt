import java.io.PrintWriter
import java.util.*



fun solve() {
    val n = ni()
    var ss: MutableList<String> = mutableListOf()
    for(i in 0..n-1){
        ss.add(nline())
    }
    var es: MutableList<MutableList<IntArray>> = mutableListOf()
    for(i in 0..5){
        es.add(mutableListOf())
    }
    var id = 1
    for(s in ss){
        val st = "kotlin".indexOf(s[0])
        val gl = ("kotlin".indexOf(s[s.length-1]) + 1) % 6
//        tr(intArrayOf(st, gl))
        es[st].add(intArrayOf(gl, id))
        id++
    }

    for(x in eulerianPathDirected(es).reversed()){
        out.print(x)
        out.print(" ")
    }
    out.println()
}

fun eulerianPathDirected(g: MutableList<MutableList<IntArray>>): List<Int> {
    val route: MutableList<Int> = mutableListOf()
    dfs(0, g, route)
    return route
}

private fun dfs(cur: Int, rem: MutableList<MutableList<IntArray>>, route: MutableList<Int>) {
    while (rem[cur].size > 0){
        val e = rem[cur][rem[cur].size-1]
        rem[cur].removeAt(rem[cur].size-1)
        dfs(e[0], rem, route)
        route.add(e[1])
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