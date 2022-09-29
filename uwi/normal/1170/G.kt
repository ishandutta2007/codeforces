//package g

import java.io.PrintWriter
import java.util.*

class Edge(val x: Int, val y: Int){
    var done = false

    override fun toString(): String = "%d %d %b".format(x, y, done)
}

fun solve() {
    val (n, m) = na()
    val g:MutableList<Deque<Edge>> = mutableListOf()
    for(i in 1..n){
        g.add(ArrayDeque<Edge>())
    }

    for(i in 1..m){
        val (x, y) = na()
        val e = Edge(x-1, y-1)
        g[e.x].add(e)
        g[e.y].add(e)
    }
    for(i in 0..n-1){
        if(g[i].size % 2 != 0){
            out.println("NO")
            return
        }
    }

    val routes: MutableList<MutableList<Int>> = mutableListOf()

    for(i in 0..n-1){
        if(g[i].size > 0) {
            val ep = ArrayDeque<Edge>()
            dfs(i, g, ep)
            val hit = hashSetOf<Int>()
            var st = ArrayDeque<Int>()
            var cur = i
            hit.add(cur)
            st.add(cur)
            for(e in ep){
                val nex = e.x + e.y - cur
                if(hit.contains(nex)){
                    val route: MutableList<Int> = mutableListOf()
                    routes.add(route)
                    while(true){
                        val last = st.pollLast()
                        route.add(last)
                        hit.remove(last)
                        if(last == nex){
                            break
                        }
                    }
                }
                hit.add(nex)
                st.add(nex)
                cur = nex
            }
        }
    }
    out.println("YES")
    out.println(routes.size)
    for(route in routes){
        out.print(route.size+1)
        for(x in route){
            out.print(" ")
            out.print(x+1)
        }
        out.print(" ")
        out.println(route[0]+1)
    }
}


fun dfs(cur: Int, g: MutableList<Deque<Edge>>, ep: Deque<Edge>){
    while(g[cur].size > 0) {
        val ne = g[cur].poll()
        if(ne.done)continue
        ne.done = true
        dfs(ne.x + ne.y - cur, g, ep)
        ep.addLast(ne)
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