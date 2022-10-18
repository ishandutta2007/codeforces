import java.util.PriorityQueue
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
        var (n, m) = readints()
        var a = IntArray(n)
        var b = IntArray(n)
        var v = mutableListOf<Pair<Int, Int>>()
        for (i in 0 until n) {
            var (x, y) = readints()
            a[i] = x
            b[i] = y
            v.add(Pair(x, i))
        }
        v.sortBy { it.first }
        v.add(Pair((2e9).toInt(), -1))
        var ans = IntArray(n)
        // var wait = mutableListOf<Pair<Int, Int>>()
        val cmp: Comparator<Pair<Int, Int>> = compareBy { it.first }
        var wait: PriorityQueue<Pair<Int, Int>> = PriorityQueue<Pair<Int, Int>>(cmp)
        for (i in 0 until n) {
            wait.add(Pair(b[v[i].second], v[i].second))
            if (v[i].first == v[i + 1].first) {
                continue
            }
            var day = v[i].first
            while (day != v[i + 1].first) {
                if (wait.size == 0) {
                    break
                }
                var c = minOf(m, wait.size)
                for (j in 0 until c) {
                    ans[wait.remove().second] = day
                }
                day++
            }
        }
        var d = 0
        for (i in 0 until n) {
            d = maxOf(d, ans[i] - b[i])
        }
        println(d)
        println(ans.joinToString(" "))
    }
}