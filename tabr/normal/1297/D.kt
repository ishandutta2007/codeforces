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
        var (nn, k) = readlongs()
        var n = nn.toInt()
        var a = readlongs()
        var s = k
        var mx = 0L
        var t = mutableListOf<Pair<Long, Int>>()
        for (i in 0 until n) {
            s += a[i]
            mx = maxOf(mx, a[i])
            t.add(Pair(a[i], i))
        }
        var b = maxOf(mx, (2L * s + nn * (nn - 1L) + 2L * nn - 1L) / (2L * nn))
        t.sortWith(compareBy({it.first}))
        var can = k
        var ans = LongArray(n)
        for (i in n - 1 downTo 0) {
            var c = minOf(b - nn + 1L + i - t[i].first, can)
            can -= c
            ans[t[i].second] = c
        }
        println(ans.joinToString(" "))
    }
}