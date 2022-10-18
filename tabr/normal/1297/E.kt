fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
	var tt = readint()
    while (tt-- > 0) {
        var (n, k) = readints()
        var g = List<MutableList<Int>>(n) { mutableListOf() }
        for (i in 0 until n - 1) {
            var (x, y) = readints()
            x--
            y--
            g[x].add(y)
            g[y].add(x)
        }
        var root = 0
        for (i in 0 until n) {
            if (g[i].size == 1) {
                root = i
                break
            }
        }
        var cnt = 0
        var ans = mutableListOf<Int>()
        fun dfs(v: Int, p: Int) {
            ans.add(v + 1)
            if (g[v].size == 1) {
                cnt++
            }
            if (cnt == k) {
                return
            }
            for (to in g[v]) {
                if (cnt == k) {
                    return
                }
                if (to == p) {
                    continue
                }
                dfs(to, v)
            }
        }
        dfs(root, -1)
        if (cnt != k) {
            println("No")
        } else {
            println("Yes")
            println(ans.size)
            println(ans.joinToString(" "))
        }
    }
}