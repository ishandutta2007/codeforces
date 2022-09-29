import java.io.PrintWriter
import java.util.*

fun solve() {
    // c!=d
    // 

    val t = ni()
    for(i in 1..t){
        solve2()
    }
}

fun solve2() {
    val n = ni()
    var cs = na()
    var ds = na()
    var ccs = cs.toMutableList().sorted().toList()
    var cds = ds.toMutableList().sorted().toList()

    var g: MutableList<MutableList<Int>> = mutableListOf()
    for(i in 1..n){
        g.add(mutableListOf())
    }
    for(i in 1..n-1){
        val (s, t) = na()
        g[s-1].add(t-1)
        g[t-1].add(s-1)
    }
    if(!ccs.equals(cds)){
        out.println("No")
        return
    }

    // hasPath
    var dep = IntArray(n)
    var pars = IntArray(n)

//    dfs(0, -1, g, dep, pars)
    fill(0, g, dep, pars)

    var maxdep = -1
    var arg = -1
    for(i in 0..n-1){
        if(cs[i] != ds[i]){
            if(dep[i] > maxdep){
                maxdep = dep[i]
                arg = i
            }
        }
    }
    if(arg == -1){
        out.println("Yes")
        out.println(0)
        return
    }

    dep = IntArray(n)
    pars = IntArray(n)
//    dfs(arg, -1, g, dep, pars)
    fill(arg, g, dep, pars)

    maxdep = -1
    var arg2 = -1
    var diff = 0
    for(i in 0..n-1){
        if(cs[i] != ds[i]){
            diff++
            if(dep[i] > maxdep){
                maxdep = dep[i]
                arg2 = i
            }
        }
    }

    // arg-arg2
    var cur = arg2
    while (true) {
        if (cs[cur] != ds[cur]) diff--
        if (cur == arg) break
        cur = pars[cur]
    }

    if(diff != 0){
        out.println("No")
        return
    }

    var route: MutableList<Int> = mutableListOf()
    cur = arg2
    while(true){
        route.add(cur)
        if(cur == arg)break
        cur = pars[cur]
    }
//    print(route)

    if(ok(route, cs, ds)){
        out.println("Yes")
        out.println(route.size)
        for(i in route){
            out.print(i+1)
            out.print(" ")
        }
        out.println()
        return
    }

    route = route.reversed().toMutableList()
    if(ok(route, cs, ds)){
        out.println("Yes")
        out.println(route.size)
        for(i in route){
            out.print(i+1)
            out.print(" ")
        }
        out.println()
        return
    }

    out.println("No")
}

fun ok(route: List<Int>, cs: List<Int>, ds: List<Int>): Boolean {
    for(i in 1..route.size-1){
        if(ds[route[i-1]] != cs[route[i]]){
            return false
        }
    }
    return ds[route[route.size-1]] == cs[route[0]]
}

fun dfs(cur: Int, pre: Int, g: MutableList<MutableList<Int>>, dep: IntArray, pars: IntArray) {
    pars[cur] = pre
    if(pre != -1){
        dep[cur] = dep[pre] + 1
    }
    for(e in g[cur]){
        if(e == pre)continue
        dfs(e, cur, g, dep, pars)
    }
}

fun fill(root: Int, g: MutableList<MutableList<Int>>, dep: IntArray, par: IntArray) {
    var q: ArrayDeque<Int> = ArrayDeque<Int>()

    q.add(root)

    Arrays.fill(dep, 99999999)
    dep[root] = 0
    par[root] = -1

    while(!q.isEmpty()){
        val cur = q.pollFirst()
        for(e in g[cur]){
            if(e == par[cur])continue
            dep[e] = dep[cur] + 1
            par[e] = cur
            q.add(e)
        }
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