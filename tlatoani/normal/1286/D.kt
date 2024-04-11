import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    if (n == 1) {
        println(0)
        return
    }
    val p = LongArray(n + 1)
    var tokenizer = StringTokenizer(readLine()!!)
    var x = tokenizer.nextToken().toLong()
    var u = tokenizer.nextToken().toLong()
    p[1] = (mint(tokenizer.nextToken().toLong()) * PERCENT).num
    val pq = PriorityQueue<Collision>(kotlin.Comparator { c, d -> c.time.compareTo(d.time) })
    for (j in 2..n) {
        tokenizer = StringTokenizer(readLine()!!)
        val y = tokenizer.nextToken().toLong()
        val v = tokenizer.nextToken().toLong()
        p[j] = (mint(tokenizer.nextToken().toLong()) * PERCENT).num
        pq.add(Collision(Rational(y - x, u + v), j - 1, 1))
        if (v > u) {
            pq.add(Collision(Rational(y - x, v - u), j - 1, 0))
        } else {
            pq.add(Collision(Rational(y - x, u - v), j - 1, 3))
        }
        x = y
        u = v
    }
    val segTree = SegmentTree(n, p)
    var answer = M0
    var prev = M1
    //println("query = ${segTree.query()}")
    while (pq.isNotEmpty()) {
        val t = pq.peek().time
        while (pq.isNotEmpty() && pq.peek().time == t) {
            segTree.updateRule(pq.peek().j, pq.peek().rule)
            pq.remove()
        }
        answer += (prev - segTree.query()) * mint(t.num) / mint(t.denom)
        prev = segTree.query()
        //println("prev = $prev")
    }
    println(answer)
}

data class Rational(val num: Long, val denom: Long): Comparable<Rational> {
    override fun compareTo(other: Rational) = (num * other.denom).compareTo(other.num * denom)
    override fun equals(other: Any?) = other is Rational && compareTo(other) == 0
}

data class Collision(val time: Rational, val j: Int, val rule: Int)

class SegmentTree(val n: Int, val p: LongArray) {
    val array: Array<LongArray>

    init {
        var l = 0
        while (1 shl l < n) {
            l++
        }
        array = Array(4) { LongArray(1 shl (l + 1)) }
        initializeValues(1, 1, n - 1)
    }

    fun query() = mint(((MOD + 1L - p[n]) * (array[0][1] + array[1][1])) + (p[n] * (array[2][1] + array[3][1])))

    fun updateRule(j: Int, rule: Int) = updateRule(j, rule, 1, 1, n - 1)

    fun updateRule(j: Int, rule: Int, node: Int, from: Int, to: Int) {
        if (from == to) {
            array[rule][node] = 0L
        } else {
            var mid = (from + to) / 2
            if (j <= mid) {
                updateRule(j, rule, 2 * node, from, mid)
            } else {
                updateRule(j, rule, (2 * node) + 1, mid + 1, to)
            }
            for (s in 0..3) {
                array[s][node] = 0L
            }
            for (mask in 0..7) {
                val s = (mask and 1) + ((mask / 4) * 2)
                array[s][node] += array[mask and 3][2 * node] * array[mask / 2][(2 * node) + 1]
            }
            for (s in 0..3) {
                array[s][node] %= MOD
            }
        }
    }

    fun initializeValues(node: Int, from: Int, to: Int) {
        if (from == to) {
            array[0][node] = (MOD + 1L - p[from]) % MOD
            array[1][node] = p[from]
            array[2][node] = array[0][node]
            array[3][node] = p[from]
        } else {
            var mid = (from + to) / 2
            initializeValues(2 * node, from, mid)
            initializeValues((2 * node) + 1, mid + 1, to)
            for (mask in 0..7) {
                val s = (mask and 1) + ((mask / 4) * 2)
                array[s][node] += array[mask and 3][2 * node] * array[mask / 2][(2 * node) + 1]
            }
            for (s in 0..3) {
                array[s][node] %= MOD
            }
        }
    }
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)
val PERCENT = Mint(100) pow -1

val MOD: Long = 998244353
val MOD_TOTIENT = (MOD - 1).toInt()

fun mint(num: Long) = Mint(num % MOD)
fun mint(num: Int) = Mint(num % MOD)

inline class Mint(val num: Long) {

    operator fun plus(k: Mint) = mint(num + k.num)
    operator fun minus(k: Mint) = mint(num + MOD - k.num)
    operator fun times(k: Mint) = mint(num * k.num)
    operator fun div(k: Mint) = this * (k pow -1)

    operator fun unaryMinus() = mint(MOD - num)
    operator fun inc() = this + M1
    operator fun dec() = this - M1

    infix fun pow(power: Int): Mint {
        var e = power
        e %= MOD_TOTIENT
        if (e < 0) {
            e += MOD_TOTIENT
        }
        if (e == 0 && num == 0L) {
            return this
        }
        var b = this
        var res = Mint(1)
        while (e > 0) {
            if (e and 1 != 0) {
                res *= b
            }
            b *= b
            e = e shr 1
        }
        return res
    }

    override fun toString(): String = num.toString()
}

/*310992689
127034380
 */

/*
3
0 1 50
1 2 50
2 1 50
83187030
 */