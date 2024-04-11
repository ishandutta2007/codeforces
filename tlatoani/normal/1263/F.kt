import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val n1 = jin.nextInt()
    val adj1 = Array(n1 + 1) { mutableListOf<Int>() }
    val parent1 = IntArray(n1 + 1)
    for (a in 2..n1) {
        val b = jin.nextInt()
        adj1[b].add(a)
        parent1[a] = b
    }
    val l1 = IntArray(n1 + 1) { Int.MAX_VALUE }
    val r1 = IntArray(n1 + 1) { 0 }
    val dfs = mutableListOf<Int>()
    val stack = Stack<Int>()
    stack.push(1)
    while (!stack.isEmpty()) {
        val a = stack.pop()
        dfs.add(a)
        for (b in adj1[a]) {
            stack.push(b)
        }
    }
    for (j in 1..n) {
        val a = jin.nextInt()
        l1[a] = j
        r1[a] = j
    }
    for (a in dfs.reversed()) {
        l1[parent1[a]] = min(l1[parent1[a]], l1[a])
        r1[parent1[a]] = max(r1[parent1[a]], r1[a])
    }
    val n2 = jin.nextInt()
    val adj2 = Array(n2 + 1) { mutableListOf<Int>() }
    val parent2 = IntArray(n2 + 1)
    for (a in 2..n2) {
        val b = jin.nextInt()
        adj2[b].add(a)
        parent2[a] = b
    }
    val l2 = IntArray(n2 + 1) { Int.MAX_VALUE }
    val r2 = IntArray(n2 + 1) { 0 }
    dfs.clear()
    stack.clear()
    stack.push(1)
    while (!stack.isEmpty()) {
        val a = stack.pop()
        dfs.add(a)
        for (b in adj2[a]) {
            stack.push(b)
        }
    }
    for (j in 1..n) {
        val a = jin.nextInt()
        l2[a] = j
        r2[a] = j
    }
    for (a in dfs.reversed()) {
        l2[parent2[a]] = min(l2[parent2[a]], l2[a])
        r2[parent2[a]] = max(r2[parent2[a]], r2[a])
    }
    val toAdd1 = Array(n + 1) { mutableListOf<Int>() }
    val toAdd2 = Array(n + 1) { mutableListOf<Int>() }
    //println("l2 = ${l2.contentToString()}")
    //println("r2 = ${r2.contentToString()}")
    for (a in 2..n1) {
        toAdd1[r1[a]].add(l1[a])
    }
    for (a in 2..n2) {
        toAdd2[r2[a]].add(l2[a])
    }
    val dp = IntArray(n + 1)
    val bit1 = BinaryIndexTree(n)
    val bit2 = BinaryIndexTree(n)
    for (j in 1..n) {
        for (l in toAdd1[j]) {
            bit1.update(l, 1)
            //println("j = $j, updating1 $l")
        }
        for (l in toAdd2[j]) {
            bit2.update(l, 1)
            //println("j = $j, updating2 $l")
        }
        for (k in 1..j) {
            dp[j] = max(dp[j], dp[k - 1] + max(bit1.query(k, j), bit2.query(k, j)))
        }
    }
    //println("dp = ${dp.contentToString()}")
    println(dp[n])
}

class BinaryIndexTree(val size: Int) {
    val array = IntArray(size + 1)

    fun update(index: Int, delta: Int) {
        var i = index
        while (i < array.size) {
            array[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Int {
        var res = 0
        var i = to
        while (i > 0) {
            res += array[i]
            i -= i and -i
        }
        return res
    }

    fun query(from: Int, to: Int) = if (from > to) 0 else (query(to) - query(from - 1))
}