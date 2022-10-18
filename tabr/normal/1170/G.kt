fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
    var (n, m) = readints()
    var e = IntArray(m)
    var g = Array(n) { mutableListOf<Int>() }
    var deg = IntArray(n)
    for(i in 0 until m){
        var (x, y) = readints()
        x--
        y--
        g[x].add(i)
        g[y].add(i)
        deg[x]++
        deg[y]++
        e[i] = x + y
    }
    for(i in 0 until n){
        if(deg[i] % 2 == 1){
            println("NO")
            return
        }
    }
    println("YES")
    var st = 0
    var pos = IntArray(n){ -1 }
    var tmp = ArrayList<List<Int>>()
    var q = IntArray(n)
    var used = IntArray(m)
    while(true){
        while(st < n && q[st] >= g[st].size){
            st++
        }
        if(st == n){
            break
        }
        while(st < n && q[st] < g[st].size && used[g[st][q[st]]] == 1){
            q[st]++
        }
        if(q[st] >= g[st].size){
            st++
            continue
        }
        var list = ArrayList<Int>()
        var v = st
        while(true){
            pos[v] = list.size
            list.add(v)
            while(used[g[v][q[v]]] == 1){
                q[v]++
            }
            var id = g[v][q[v]]
            q[v]++
			var to = e[id] - v
            used[id] = 1
            if(to == st){
                break
            }
            if(pos[to] >= 0){
                var d = list.subList(pos[to], list.size)
                tmp.add(d.toList())
                for(z in d){
                    pos[z] = -1
                }
                d.clear()
            }
            v = to
        }
        tmp.add(list)
        for(z in list){
            pos[z] = -1
        }
    }
    println(tmp.size)
    var ans = tmp.joinToString("\n") { l -> "${l.size + 1} ${l.joinToString(" ") { (it + 1).toString() }} ${l[0] + 1}" }
    println(ans)
}