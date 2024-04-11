var t = Array<Long>(2500000, {0})
var d = Array<Long>(666666, {0})
var A = 600100
fun get(v : Int, tl : Int, tr : Int, l : Int, r: Int) : Long{
    if (l > r)
        return 0
    if (l == tl && r == tr)
        return t[v]
    var tm = (tl + tr) / 2
    return  maxOf(get (v*2, tl, tm, l, minOf(r,tm)),
        get (v*2+1, tm+1, tr, maxOf(l,tm+1), r))
    }
fun update(v : Int, tl : Int, tr : Int, pos : Int, new_val : Long) {
    if (tl == tr)
        t[v] = new_val
    else {
        var tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val)
        else
            update (v*2+1, tm+1, tr, pos, new_val)
        t[v] =  maxOf(t[v*2], t[v*2+1]);
    }
}

fun main() {
    var (n,m) = readv()
    var k = Array(n, {0})
    var a = Array(n, {MutableList<Int>(0, {0})})
    var b = Array(n, {MutableList<Int>(0, {0})})
    var bar = Array(m+1, {MutableList<Pair<Int, Int>>(0, {Pair(0,0)})})
    for(i in 0 until n) {
        k[i] = read()
        var ca = readv()
        for(x in ca) a[i].add(x)
        var cb = readv()
        for(x in cb) b[i].add(x)
        for(j in 0 until k[i]) {
            bar[b[i][j]].add(Pair(-i, a[i][j]))
        }
    }
    var ans : Long = 0
    for(nb in 0 until m+1) {
        bar[nb].sortBy { it.first }
        for(x in bar[nb]) {
            var i = -x.first
            var sum = i + nb
            var nmax = get(1, 0, A-1, sum+1, A-1)
            if(d[sum] < nmax + x.second) {
                d[sum] = nmax + x.second
                update(1, 0, A-1, sum, d[sum])
                if(nb >= m - i) ans = maxOf(d[sum], ans)
            }
        }
    }
    println(ans)
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}