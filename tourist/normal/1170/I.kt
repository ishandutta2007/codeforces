val md = 998244353

fun add(a: Int, b: Int) = (a + b) % md
fun mul(a: Int, b: Int) = ((a.toLong() * b) % md).toInt()

var sum = IntArray(0)
var push = IntArray(0)

fun modify(x: Int, l: Int, r: Int, ll: Int, rr: Int, v: Int) {
    if (r < ll || rr < l) {
        return
    }
    if (ll <= l && r <= rr) {
        if (v >= 0) {
            sum[x] = add(sum[x], v)
        } else {
            sum[x] = mul(sum[x], 2)
            push[x] = mul(push[x], 2)
        }
        return
    }
    if (push[x] != 1) {
        push[x + x] = mul(push[x + x], push[x])
        sum[x + x] = mul(sum[x + x], push[x])
        push[x + x + 1] = mul(push[x + x + 1], push[x])
        sum[x + x + 1] = mul(sum[x + x + 1], push[x])
        push[x] = 1
    }
    val y = (l + r) shr 1
    if (ll <= y) {
        modify(x + x, l, y, ll, rr, v)
    }
    if (rr > y) {
        modify(x + x + 1, y + 1, r, ll, rr, v)
    }
    sum[x] = add(sum[x + x], sum[x + x + 1])
}

fun getSum(x: Int, l: Int, r: Int, ll: Int, rr: Int) : Int {
    if (r < ll || rr < l) {
        return 0
    }
    if (ll <= l && r <= rr) {
        return sum[x]
    }
    if (push[x] != 1) {
        push[x + x] = mul(push[x + x], push[x])
        sum[x + x] = mul(sum[x + x], push[x])
        push[x + x + 1] = mul(push[x + x + 1], push[x])
        sum[x + x + 1] = mul(sum[x + x + 1], push[x])
        push[x] = 1
    }
    val y = (l + r) shr 1
    var res = 0
    if (ll <= y) {
        res = add(res, getSum(x + x, l, y, ll, rr))
    }
    if (rr > y) {
        res = add(res, getSum(x + x + 1, y + 1, r, ll, rr))
    }
    sum[x] = add(sum[x + x], sum[x + x + 1])
    return res
}

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val from = IntArray(n)
    val to = IntArray(n)
    for (i in 0 until n) {
        val (foo, bar) = readLine()!!.split(" ").map { it.toInt() }
        from[i] = foo
        to[i] = bar
    }
    val coords = Array<Pair<Int, Int>>(2 * n, {i -> if (i < n) Pair(from[i], i) else Pair(to[i - n], i)})
    coords.sortBy({x -> x.first})
    var last = -1
    var t = -1
    for (c in coords) {
        if (c.first > last) {
            last = c.first
            ++t
        }
        if (c.second < n) {
            from[c.second] = 2 * t
        } else {
            to[c.second - n] = 2 * t
        }
    }
    t = 2 * t + 1
    var balance = IntArray(t + 1)
    for (i in 0 until n) {
        balance[from[i]]++
        balance[to[i] + 1]--
    }
    for (i in 0 until t) {
        balance[i + 1] += balance[i]
    }
    var mapReal = IntArray(t + 1)
    var iReal = -1
    for (i in 0 until t) {
        if (balance[i] != 0) {
            iReal++
            mapReal[i] = iReal
        }
    }
    t = iReal + 1
    for (i in 0 until n) {
        from[i] = mapReal[from[i]]
        to[i] = mapReal[to[i]]
    }
    var iOrder = IntArray(n)
    for (i in 0 until n) {
        iOrder[i] = i
    }
    var order = iOrder.sortedBy({i -> from[i]})
    var p2 = IntArray(n + 1)
    p2[0] = 1
    for (i in 1..n) {
        p2[i] = mul(p2[i - 1], 2)
    }
    var dp = IntArray(n)
    sum = IntArray(4 * t + 10)
    push = IntArray(4 * t + 10)
    for (i in 0 until 4 * t + 10) {
        push[i] = 1
    }
    modify(1, 0, t - 1, 0, 0, 1)
    var left = n
    var ans = 0
    for (i in order) {
        left--
        dp[i] = getSum(1, 0, t - 1, from[i], to[i])
        if (to[i] == t - 1) {
            ans = add(ans, mul(dp[i], p2[left]))
        } else {
            modify(1, 0, t - 1, to[i] + 1, t - 1, -1)
            modify(1, 0, t - 1, to[i] + 1, to[i] + 1, dp[i])
        }
    }
    println(ans)
}