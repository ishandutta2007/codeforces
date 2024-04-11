import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var n = 0
var d = 0
var sl = IntArray(0)
var sr = IntArray(0)
var h = IntArray(0)

var who = Array(0) {ArrayList<Int>()}
var max = IntArray(0)
var lf = IntArray(0)
var rg = IntArray(0)

fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun modify(x: Int, l: Int, r: Int, ll: Int, rr: Int, v: Int) {
    if (r < ll || rr < l) {
        return
    }
    val y = (l + r) shr 1
    var z = x + 2 * (y - l + 1)
    if (ll <= l && r <= rr) {
        if (v >= 0) {
            who[x].add(v)
        } else {
            myAssert(who[x].get(who[x].size - 1) == -v - 1)
            who[x].removeAt(who[x].size - 1)
        }
    } else {
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v)
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v)
        }
    }
    if (who[x].isEmpty()) {
        max[x] = -1
        lf[x] = -1
        rg[x] = -1
    } else {
        var u = who[x].get(who[x].size - 1)
        max[x] = h[u]
        lf[x] = u
        rg[x] = u
    }
    if (l < r) {
        if (maxOf(max[x + 1], max[z]) > max[x]) {
            max[x] = maxOf(max[x + 1], max[z])
            lf[x] = -1
            rg[x] = -1
        }
        if (max[x + 1] == max[x] && max[x] >= 0) {
            if (lf[x] == -1 || sl[lf[x + 1]] < sl[lf[x]]) {
                lf[x] = lf[x + 1]
            }
            if (rg[x] == -1 || sr[rg[x + 1]] > sr[rg[x]]) {
                rg[x] = rg[x + 1]
            }
        }
        if (max[z] == max[x] && max[x] >= 0) {
            if (lf[x] == -1 || sl[lf[z]] < sl[lf[x]]) {
                lf[x] = lf[z]
            }
            if (rg[x] == -1 || sr[rg[z]] > sr[rg[x]]) {
                rg[x] = rg[z]
            }
        }
        if (max[x] != -1) {
            myAssert(h[lf[x]] == max[x])
            myAssert(h[rg[x]] == max[x])
        }
    }
}

fun getMax(x: Int, l: Int, r: Int, ll: Int, rr: Int) : Triple<Int, Int, Int> {
    if (r < ll || rr < l) {
        return Triple(-1, -1, -1)
    }
    if (ll <= l && r <= rr) {
        return Triple(max[x], lf[x], rg[x])
    }
    val y = (l + r) shr 1
    var z = x + 2 * (y - l + 1)
    var rmax = -1
    var rlf = -1
    var rrg = -1
    if (!who[x].isEmpty()) {
        var u = who[x].get(who[x].size - 1)
        rmax = h[u]
        rlf = u
        rrg = u
    }
    if (ll <= y) {
        var t = getMax(x + 1, l, y, ll, rr)
        if (t.first > rmax) {
            rmax = t.first
            rlf = -1
            rrg = -1
        }
        if (t.first == rmax) {
            if (rlf == -1 || sl[t.second] < sl[rlf]) {
                rlf = t.second
            }
            if (rrg == -1 || sr[t.third] > sr[rrg]) {
                rrg = t.third
            }
        }
    }
    if (rr > y) {
        var t = getMax(z, y + 1, r, ll, rr)
        if (t.first > rmax) {
            rmax = t.first
            rlf = -1
            rrg = -1
        }
        if (t.first == rmax) {
            if (rlf == -1 || sl[t.second] < sl[rlf]) {
                rlf = t.second
            }
            if (rrg == -1 || sr[t.third] > sr[rrg]) {
                rrg = t.third
            }
        }
    }
    if (rmax != -1) {
        myAssert(h[rlf] == rmax)
        myAssert(h[rrg] == rmax)
    }
    return Triple(rmax, rlf, rrg)
}

var ans = 0

fun add(i: Int) {
    ans += 1
    modify(0, 0, d - 1, sl[i], sr[i], i)
}

fun remove(i: Int) {
    ans -= 1
    modify(0, 0, d - 1, sl[i], sr[i], -i - 1)
}

fun main(args: Array<String>) {
    var (n_, d_) = readInts()
    n = n_
    d = d_
    sl = IntArray(n)
    sr = IntArray(n)
    h = IntArray(n)
    for (i in 0 until n) {
        var (x, y) = readInts()
        sl[i] = x - 1
        sr[i] = y - 1
    }
    who = Array(2 * d - 1) {ArrayList<Int>()}
    max = IntArray(2 * d - 1) {-1}
    lf = IntArray(2 * d - 1) {-1}
    rg = IntArray(2 * d - 1) {-1}
    for (i in 0 until n) {
        while (true) {
            val nd = getMax(0, 0, d - 1, sl[i], sr[i])
            if (nd.first == -1 || sl[nd.second] < sl[i] || sr[nd.third] > sr[i]) {
                h[i] = nd.first + 1
                break
            }
            remove(nd.second)
            if (nd.third != nd.second) {
                remove(nd.third)
            }
            while (true) {
                var nx = getMax(0, 0, d - 1, sl[i], sr[i])
                if (nx.first != nd.first) {
                    break
                }
                remove(nx.second)
                if (nx.second != nx.third) {
                    remove(nx.third)
                }
            }
        }
        add(i)
        println(ans)
    }
}