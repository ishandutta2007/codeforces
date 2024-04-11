import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.system.exitProcess

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val matrixA = mutableMapOf<List<Int>, LinkedList<Int>>()
    for (y in 1..n) {
        val row = jin.readLine().split(" ").map { it.toInt() }
        matrixA.computeIfAbsent(row) { LinkedList() }.addLast(y)
    }
    val matrixB = Array(n) {
        val row = jin.readLine().split(" ").map { it.toInt() }
        val index = matrixA[row]?.let { ll -> if (ll.isEmpty()) null else ll.removeFirst() }
        if (index == null) {
            println(-1)
            exitProcess(0)
        }
        listOf(index) + row
    }
    var diffs = (1 until n).toList()
    var spots = Array(n) { mutableListOf<Int>() }
    val amts = IntArray(m + 1) { x ->
        var res = 0
        for (y in 1 until n) {
            if (matrixB[y - 1][x] > matrixB[y][x]) {
                spots[y].add(x)
                res++
            }
        }
        res
    }
    val stack = Stack<Int>()
    stack.addAll((0..m).filter { x -> amts[x] == 0 })
    val answer = mutableListOf<Int>()
    while (stack.isNotEmpty()) {
        val x = stack.pop()
        answer.add(x)
        val newDiffs = mutableListOf<Int>()
        for (y in diffs) {
            if (matrixB[y - 1][x] < matrixB[y][x]) {
                for (x2 in spots[y]) {
                    amts[x2]--
                    if (amts[x2] == 0) {
                        stack.push(x2)
                    }
                }
            } else {
                newDiffs.add(y)
            }
        }
        diffs = newDiffs
    }
    if (diffs.isEmpty()) {
        val naturalIndex = answer.indexOf(0)
        println(naturalIndex)
        println(answer.subList(0, naturalIndex).reversed().joinToString(" "))
    } else {
        println(-1)
    }
}