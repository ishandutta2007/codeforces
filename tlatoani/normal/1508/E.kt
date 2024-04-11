import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val labels = (listOf(0) + jin.readLine().split(" ").map { it.toInt() }).toIntArray()
    val parent = IntArray(n + 1)
    val children = Array(n + 1) { mutableListOf<Int>() }
    val childrenAMT = IntArray(n + 1)
    for (j in 2..n) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        parent[b] = a
        children[a].add(b)
        childrenAMT[a]++
    }
    var aPrime = (1..n).filter { children[it].any { b -> labels[b] > labels[it] }}.minBy { labels[it] } ?: 0
    var bPrime = children[aPrime].filter { labels[it] > labels[aPrime] }.minBy { labels[it] } ?: 0
    var addend = 0
    while (bPrime != 0) {
        addend++
        val x = labels[aPrime]
        val y = labels[bPrime]
        labels[aPrime] = y
        labels[bPrime] = x
        aPrime = bPrime
        bPrime = children[aPrime].filter { labels[it] > labels[aPrime] }.minBy { labels[it] } ?: 0
    }
    val positions = IntArray(n + 1)
    for (a in 1..n) {
        positions[labels[a]] = a
    }
    val appears = BooleanArray(n + 1)
    val dfs = IntArray(n + 1)
    dfs[1] = 1
    appears[1] = true
    var prev = 1
    var k = 2
    var until = 0
    for (j in 1..n) {
        var a = positions[j]
        if (a == 1) {
            until = j
            break
        }
        val stack = Stack<Int>()
        if (childrenAMT[a] != 0) {
            println("NO")
            return
        }
        while (!appears[a]) {
            stack.push(a)
            a = parent[a]
        }
        if (a != prev) {
            println("NO")
            return
        }
        while (stack.isNotEmpty()) {
            dfs[k] = stack.pop()
            appears[dfs[k]] = true
            k++
        }
        prev = parent[positions[j]]
        childrenAMT[prev]--
    }
    for (a in 1..n) {
        if (!appears[a]) {
            dfs[labels[a]] = a
        }
    }
    val stack = Stack<Int>()
    stack.push(1)
    val bit = BinaryIndexTree(1, n)
    bit.update(labels[1], 1)
    var answer = 0L
    for (j in 2..n) {
        val a = dfs[j]
        while (stack.isNotEmpty() && stack.peek() != parent[a]) {
            bit.update(labels[stack.peek()], -1)
            stack.pop()
        }
        if (stack.isEmpty()) {
            println("NO")
            return
        }
        answer += bit[labels[a], n]
        bit.update(labels[a], 1)
        stack.push(a)
    }
    val proper = IntArray(n + 1)
    for (j in 1..n) {
        proper[j] = labels[dfs[j]]
    }
    val rem = proper.filter { it >= until }
    if (rem != rem.sorted()) {
        println("NO")
        return
    }
    val dfsPosition = IntArray(n + 1)
    for (j in 1..n) {
        dfsPosition[dfs[j]] = j
    }
    println("YES")
    println(answer - addend)
    println(dfsPosition.toList().subList(1, n + 1).joinToString(" "))
}

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = IntArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Int) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Int {
        var res = 0
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            i -= i and -i
        }
        return res
    }

    operator fun get(from: Int, to: Int) = if (to < from) 0 else query(to) - query(from - 1)
}