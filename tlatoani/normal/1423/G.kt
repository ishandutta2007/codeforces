import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val flowers = jin.readLine().split(" ").map { it.toInt() }
    val types = mutableMapOf<Int, TreeSet<Segment>>()
    val bit = RangeBIT(n)
    val overall = TreeSet<Segment>(compareBy { it.from })
    for (j in 1..n) {
        val f = flowers[j - 1]
        if (f !in types) {
            types[f] = TreeSet<Segment>(compareBy { it.from })
            types[f]!!.add(Segment(0, 0, f))
        }
        val j2 = types[f]!!.last().to
        bit.update(1, j - j2, 1L)
        bit.update(n + 2 - j, n + 1 - j2, -1L)
        types[f]!!.add(Segment(j, j, f))
        overall.add(Segment(j, j, f))

    }
    fun changeContribution(segment: Segment, sign: Long) {
        val left = types[segment.type]!!.lower(segment)!!
        bit.update(1, 1, sign * (segment.to - segment.from).toLong())
        bit.update(n + 2 - segment.to, n + 1 - segment.from, -sign)
        bit.update(1, segment.from - left.to, sign)
        bit.update(n + 2 - segment.from, n + 1 - left.to, -sign)
    }
    fun remove(segment: Segment) {
        changeContribution(segment, -1L)
        val right = types[segment.type]!!.higher(segment)
        if (right != null) {
            changeContribution(right, -1L)
        }
        overall.remove(segment)
        types[segment.type]!!.remove(segment)
        if (right != null) {
            changeContribution(right, 1L)
        }
    }
    fun add(segment: Segment) {
        if (segment.type !in types) {
            types[segment.type] = TreeSet<Segment>(compareBy { it.from })
            types[segment.type]!!.add(Segment(0, 0, segment.type))
        }
        val right = types[segment.type]!!.higher(segment)
        if (right != null) {
            changeContribution(right, -1L)
        }
        overall.add(segment)
        types[segment.type]!!.add(segment)
        changeContribution(segment, 1L)
        if (right != null) {
            changeContribution(right, 1L)
        }
    }
    val out = StringBuilder()
    for (j in 1..q) {
        val line = jin.readLine().split(" ").map { it.toInt() }
        if (line[0] == 1) {
            val l = line[1]
            val r = line[2]
            val x = line[3]
            while (true) {
                val segment = overall.floor(Segment(r, r, 0))
                if (segment == null || segment.to < l) {
                    break
                }
                remove(segment)
                if (segment.to > r) {
                    add(Segment(r + 1, segment.to, segment.type))
                }
                if (segment.from < l) {
                    add(Segment(segment.from, l - 1, segment.type))
                    break
                }
            }
            add(Segment(l, r, x))
            //println(overall)
            /*for (k in 1..n) {
                print("${bit[1, k]} ")
            }*/
            //println()
        } else {
            val k = line[1]
            out.appendln(bit[1, k])
        }
    }
    print(out)
}

data class Segment(val from: Int, val to: Int, val type: Int)

class RangeBIT internal constructor(treeTo: Int) {
    val value: LongArray
    val weightedVal: LongArray
    fun updateHelper(index: Int, delta: Long) {
        val weightedDelta = index.toLong() * delta
        var j = index
        while (j < value.size) {
            value[j] += delta
            weightedVal[j] += weightedDelta
            j += j and -j
        }
    }

    fun update(from: Int, to: Int, delta: Long) {
        //println("update($from, $to) + $delta")
        if (from <= to) {
            updateHelper(from, delta)
            updateHelper(to + 1, -delta)
        }
    }

    fun query(to: Int): Long {
        var res: Long = 0
        var weightedRes: Long = 0
        var j = to
        while (j > 0) {
            res += value[j]
            weightedRes += weightedVal[j]
            j -= j and -j
        }
        return (to + 1).toLong() * res - weightedRes
    }

    operator fun get(from: Int, to: Int): Long {
        return if (to < from) {
            0
        } else query(to) - query(from - 1)
    }

    init {
        value = LongArray(treeTo + 2)
        weightedVal = LongArray(treeTo + 2)
    }
}

/*
10 10
1 2 6 7 6 4 6 8 9 2
2 1
2 2
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 10


 */