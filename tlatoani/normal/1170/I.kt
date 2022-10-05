import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val xs = TreeSet<Int>()
    val segments = Array(n) {
        val from = jin.nextInt()
        val to = jin.nextInt()
        xs += from
        xs += to
        Segment(from, to)
    }
    val bij = mutableMapOf<Int, Int>()
    var ix = 0
    for (x in xs) {
        ix++
        bij[x] = ix
    }
    for (i in 0 until n) {
        segments[i] = Segment(bij[segments[i].from]!!, bij[segments[i].to]!!)
    }
    segments.sort()
    val ends = TreeSet<Int>()
    ends.add(0)
    for (segment in segments) {
        while (segment.from <= ends.lower(segment.to)!!) {
            ends.remove(ends.lower(segment.to)!!)
        }
        ends.add(segment.to)
    }
    //println("ends = $ends")
    val segTree = LazySegmentTree(1, ix)
    for (end in ends) {
        if (end < ix && !ends.contains(end + 1)) {
            segTree.update(end + 1, M1)
        }
    }
    for (segment in segments) {
        //println("segment = $segment")
        if (ends.contains(segment.from - 1) && segment.from == segment.to && ends.contains(segment.to)) {
            segTree.update(segment.from, segTree.query(segment.from, segment.to) + M1)
            //println("query = ${segTree.query(segment.to, segment.to)}")
            continue
        }
        segTree.update(segment.to, segTree.query(segment.from, segment.to))
        segTree.update2(ends.lower(segment.from)!! + 1, segment.from - 1, 1)
        //println("query = ${segTree.query(segment.to, segment.to)}")
    }
    var answer = M1
    ends.remove(0)
    for (end in ends) {
        answer *= segTree.query(end, end)
    }
    println(answer)
}

data class Segment(val from: Int, val to: Int): Comparable<Segment> {
    override fun compareTo(other: Segment) = compareValuesBy(this, other, { it.to }, { -it.from })
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)

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

class LazySegmentTree(val treeFrom: Int, val treeTo: Int) {
    val array: Array<Mint>
    val lazy: IntArray

    fun combine(a: Long, b: Long): Long {
        return Math.max(a, b)
    }

    init {
        val length = treeTo - treeFrom + 1
        var l: Int
        l = 0
        while (1 shl l < length) {
            l++
        }
        array = Array(1 shl l + 1) { M0 }
        lazy = IntArray(1 shl l + 1)
    }

    fun propagate(node: Int) {
        array[node] *= M2 pow lazy[node]
        if (node shl 1 < array.size) {
            lazy[node shl 1] += lazy[node]
            lazy[(node shl 1) + 1] += lazy[node]
        }
        lazy[node] = 0
    }

    fun eval(node: Int): Mint {
        return array[node] * (M2 pow lazy[node])
    }


    fun update(index: Int, delta: Mint) {
        update(1, treeFrom, treeTo, index, delta)
    }

    fun update(node: Int, segFrom: Int, segTo: Int, index: Int, delta: Mint) {
        propagate(node)
        array[node] += delta
        if (segFrom != segTo) {
            val mid = (segFrom + segTo) shr 1
            if (index <= mid) {
                update(node shl 1, segFrom, mid, index, delta)
            } else {
                update((node shl 1) + 1, mid + 1, segTo, index, delta)
            }
        }
    }

    fun update2(from: Int, to: Int, delta: Int) {
        update2(1, treeFrom, treeTo, from, to, delta)
    }

    fun update2(node: Int, segFrom: Int, segTo: Int, from: Int, to: Int, delta: Int) {
        if (segTo < from || segFrom > to) return
        if (segFrom >= from && segTo <= to) {
            lazy[node] += delta
            return
        }
        propagate(node)
        val mid = segFrom + segTo shr 1
        update2(node shl 1, segFrom, mid, from, to, delta)
        update2((node shl 1) + 1, mid + 1, segTo, from, to, delta)
        array[node] = eval(node shl 1) + eval((node shl 1) + 1)
    }

    fun query(from: Int, to: Int): Mint {
        if (to < from) {
            return M0
        }
        return query(1, treeFrom, treeTo, from, to)
    }

    fun query(node: Int, segFrom: Int, segTo: Int, from: Int, to: Int): Mint {
        if (segTo < from || segFrom > to) return M0
        if (segFrom >= from && segTo <= to) {
            return eval(node)
        }
        propagate(node)
        val mid = segFrom + segTo shr 1
        val res = query(node shl 1, segFrom, mid, from, to) +
                query((node shl 1) + 1, mid + 1, segTo, from, to)
        array[node] = eval(node shl 1) + eval((node shl 1) + 1)
        return res
    }
}