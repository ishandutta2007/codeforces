import java.util.*
import kotlin.math.*

fun Solve() {
    val (k, n) = readLine()!!.split(" ").map{ it.toInt() }
    val p = readLine()!!.split(" ").map{ it.toInt() }
    val x = readLine()!!.split(" ").map{ it.toInt() }
    val gap = IntArray(1000000)
    val lf = IntArray(n)
    val rg = IntArray(n)
    val vis = BooleanArray(1000001)
    for (d in p) vis[d] = true
    val which = IntArray(1000001, { i -> -1})
    for (i in 0 until n) {
        which[x[i]] = i
    }
    for (i in 0 until n) {
        lf[i] = if (i > 0) { i - 1 } else -1
        rg[i] = if (i + 1 < n) { i + 1 } else -1
    }
    var kind = 0
    var rp = IntArray(1000001, { i -> -1 })
    for (x in p) {
        var y = x
        while (y <= 1000000) {
            if (rp[y] == -1) {
                rp[y] = x
            }
            y += x
        }
    }
    var no = 0
    for (i in 1 until n) {
        var g = rp[x[i] - x[i - 1]]
        if (g == -1) {
            no += 1
        } else {
            if (gap[g] == 0) kind += 1
            gap[g] += 1
        }
    }
    val used = BooleanArray(n)
    val orig = gap.clone()
    val okind = kind
    val ono = no
    for (d in p) {
        val update = ArrayList<Int>()
        val gupdated = ArrayList<Int>()
        val v = ArrayList<Int>()
        var cur = x[0]
        var cnt = 0
        while (cur <= 1000000) {
            if (which[cur] != -1) {
                used[which[cur]] = true
                v.add(which[cur])
                cnt += 1
                val i = which[cur]
                if (lf[i] != -1) {
                    var g = rp[x[i] - x[lf[i]]]
                    gupdated.add(g)
                    if (g == -1) {
                        no -= 1
                    } else {
                        gap[g] -= 1
                        if (gap[g] == 0) kind -= 1
                    }
                }
                if (rg[i] != -1) {
                    var g = rp[x[rg[i]] - x[i]]
                    gupdated.add(g)
                    if (g == -1) {
                        no -= 1
                    } else {
                        gap[g] -= 1
                        if (gap[g] == 0) kind -= 1
                    }
                }
                if (lf[i] != -1) {
                    rg[lf[i]] = rg[i]
                    update.add(lf[i])
                }
                if (rg[i] != -1) {
                    lf[rg[i]] = lf[i]
                    update.add(rg[i])
                }
                if (lf[i] != -1 && rg[i] != -1) {
                    var g = rp[x[rg[i]] - x[lf[i]]]
                    gupdated.add(g)
                    if (g == -1) {
                        no += 1
                    } else {
                        if (gap[g] == 0) kind += 1
                        gap[g] += 1
                    }
                }
            }
            cur += d
        }
        var a = 0
        while (a < n && used[a]) a += 1
        if (a < n) {
            used[a] = true
            v.add(a)
        }
        var b = a
        while (b < n && used[b]) b += 1
        if (b < n) {
            used[b] = true
            v.add(b)
        }
        if (no == 0) {
            if (a == n) {
                println("YES")
                println("${x[0]} ${d}")
                println("${1} ${d}")
                return
            }
            if (b == n) {
                println("YES")
                println("${x[0]} ${d}")
                println("${x[a]} ${d}")
                return
            }
            var dist = x[b] - x[a]
            assert(rp[dist] != -1)
            val g = rp[dist]
            if (gap[g] == n - cnt - 1) {
                println("YES")
                println("${x[0]} ${d}")
                println("${x[a]} ${g}")
                return
            }
        }
        for (e in update) {
            lf[e] = if (e > 0) { e - 1 } else -1
            rg[e] = if (e + 1 < n) { e + 1 } else -1
        }
        for (e in gupdated) {
            if (e >= 0) gap[e] = orig[e]
        }
        for (e in v) {
            used[e] = false
        }
        kind = okind
        no = ono
    }
    println("NO")
}

fun main() {
    var t = 1
    while (t-- > 0) {
        Solve()
    }
}