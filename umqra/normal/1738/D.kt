import java.lang.Integer.max
import java.util.Scanner
import kotlin.math.min

fun reconstruct(start: Int, type: Int, refs: List<List<Int>>, p: MutableList<Int>): Pair<Int, Int> {
    var range = if (type == 0) start to refs.size else 0 to start
    for (i in 0 until refs[start].size) {
        p.add(refs[start][i])
        val update = reconstruct(refs[start][i], 1 - type, refs, p)
        range = max(range.first, update.first) to min(range.second, update.second)
    }
    return range
}

fun main(args: Array<String>) {
    val reader = Scanner(System.`in`)
    val tests = reader.nextInt()
    for (t in 0 until tests) {
        val n = reader.nextInt()
        val refs = ArrayList<MutableList<Int>>(n + 2)
        for (i in 0 until n + 2) {
            refs.add(mutableListOf())
        }
        for (i in 0 until n) {
            val value = reader.nextInt()
            refs[value].add(i + 1)
        }
        for (i in 0 until n + 2) {
            refs[i] = refs[i].sortedBy { refs[it].size }.toMutableList()
        }
        val p = mutableListOf<Int>()
        val range = if (refs[0].size > 0) reconstruct(0, 0, refs, p) else reconstruct(n + 1, 1, refs, p)
        println("${range.first}")
        for (v in p) {
            print("$v ")
        }
        println()
    }
}