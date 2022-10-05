import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val p = tokenizer.nextToken().toInt()
    val weapons = Array(n) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        Thing(line.substring(0, six).toLong(), line.substring(six + 1).toLong())
    }
    val armors = Array(m) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        Thing(line.substring(0, six).toLong(), line.substring(six + 1).toLong())
    }
    val monsters = Array(p) {
        tokenizer = StringTokenizer(jin.readLine())
        val x = tokenizer.nextToken().toLong()
        val y = tokenizer.nextToken().toLong()
        val z = tokenizer.nextToken().toLong()
        Monster(x + 1L, y + 1L, z)
    }
    val ys = TreeSet<Long>()
    for (armor in armors) {
        ys.add(armor.modifer)
    }
    val yix = mutableMapOf<Long, Int>()
    var ix = 0
    for (y in ys) {
        ix++
        yix[y] = ix
    }
    val segTree = LazySegmentTree(1, ix)
    for (armor in armors) {
        val j = yix[armor.modifer]!!
        val curr = segTree.query(j, j)
        if (curr == 0L || armor.cost < -curr) {
            segTree.update(j, j, -curr - armor.cost)
        }
    }
    /*for (j in 1..ix) {
        println("query($j) = ${segTree.query(j, j)}")
    }*/
    val pq = PriorityQueue<Monster>(compareBy { it.def })
    pq.addAll(monsters)
    weapons.sortBy { it.modifer }
    var answer = Long.MIN_VALUE
    for (weapon in weapons) {
        while (pq.isNotEmpty() && pq.peek().def <= weapon.modifer) {
            val monster = pq.remove()
            val ceil = ys.ceiling(monster.att)
            if (ceil != null) {
                val j = yix[ceil]!!
                segTree.update(j, ix, monster.pesos)
            }
        }
        answer = max(answer, segTree.query(1, ix) - weapon.cost)
        /*println("weapon = $weapon, answer = $answer")
        for (j in 1..ix) {
            println("query($j) = ${segTree.query(j, j)}")
        }*/
    }
    println(answer)
}

data class Thing(val modifer: Long, val cost: Long)
data class Monster(val def: Long, val att: Long, val pesos: Long)

class LazySegmentTree(val treeFrom: Int, val treeTo: Int) {
    val `val`: LongArray
    val lazy: LongArray

    fun combine(a: Long, b: Long): Long {
        return max(a, b)
    }

    companion object {
        const val IDENTITY = Long.MIN_VALUE
    }

    fun propagate(node: Int) {
        `val`[node] += lazy[node]
        if (node shl 1 < `val`.size) {
            lazy[node shl 1] += lazy[node]
            lazy[(node shl 1) + 1] += lazy[node]
        }
        lazy[node] = 0
    }

    fun eval(node: Int): Long {
        return `val`[node] + lazy[node]
    }

    fun update(from: Int, to: Int, delta: Long) {
        update(1, treeFrom, treeTo, from, to, delta)
    }

    fun update(node: Int, segFrom: Int, segTo: Int, from: Int, to: Int, delta: Long) {
        if (segTo < from || segFrom > to) return
        if (segFrom >= from && segTo <= to) {
            lazy[node] += delta
            return
        }
        propagate(node)
        val mid = segFrom + segTo shr 1
        update(node shl 1, segFrom, mid, from, to, delta)
        update((node shl 1) + 1, mid + 1, segTo, from, to, delta)
        `val`[node] = combine(eval(node shl 1), eval((node shl 1) + 1))
    }

    fun query(from: Int, to: Int): Long {
        return query(1, treeFrom, treeTo, from, to)
    }

    fun query(node: Int, segFrom: Int, segTo: Int, from: Int, to: Int): Long {
        if (segTo < from || segFrom > to) return IDENTITY
        if (segFrom >= from && segTo <= to) {
            return eval(node)
        }
        propagate(node)
        val mid = segFrom + segTo shr 1
        val res = combine(
                query(node shl 1, segFrom, mid, from, to),
                query((node shl 1) + 1, mid + 1, segTo, from, to)
        )
        `val`[node] = combine(eval(node shl 1), eval((node shl 1) + 1))
        return res
    }

    init {
        val length = treeTo - treeFrom + 1
        var l: Int
        l = 0
        while (1 shl l < length) {
            l++
        }
        `val` = LongArray(1 shl l + 1)
        lazy = LongArray(1 shl l + 1)
    }
}

/*
2 4 3
2 3
4 7
2 4
3 2
3 1
5 11
1 2 4
2 1 6
3 4 6
 */