import java.util.*
import kotlin.math.max

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val attacks = mutableListOf<Attack>()
    for (t in 0 until n) {
        val k = readLine()!!.toInt()
        val tokenizerDamage = StringTokenizer(readLine()!!)
        val tokenizerRequiredBarricades = StringTokenizer(readLine()!!)
        repeat(k) {
            val d = tokenizerDamage.nextToken().toLong()
            val b = tokenizerRequiredBarricades.nextToken().toInt()
            attacks.add(Attack(d, b, b + t))
        }
    }
    attacks.sortWith(compareBy({ -it.neededBarricades }, { it.maxInitialBarricades }))
    val segTree = SegmentTree(-1, n + m)
    for (attack in attacks) {
        if (attack.maxInitialBarricades >= m) {
            segTree[attack.maxInitialBarricades] = max(segTree[attack.maxInitialBarricades], segTree[-1, attack.maxInitialBarricades - 1] + attack.damage)
        }
    }
    println(segTree[-1, n + m])
}

data class Attack(val damage: Long, val neededBarricades: Int, val maxInitialBarricades: Int)

class SegmentTree(val treeFrom: Int, treeTo: Int) {
    val value: LongArray
    val length: Int

    init {
        var e = 0
        while (1 shl e < treeTo - treeFrom + 1) {
            e++
        }
        value = LongArray(1 shl (e + 1))
        length = 1 shl e
    }

    operator fun set(index: Int, delta: Long) {
        var node = index - treeFrom + length
        value[node] = delta
        node = node shr 1
        while (node > 0) {
            value[node] = max(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromaxdex: Int, toIndex: Int): Long {
        if (toIndex < fromaxdex) {
            return 0L
        }
        var from = fromaxdex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res = 0L
        while (from + (from and -from) <= to) {
            res = max(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = max(res, value[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
}