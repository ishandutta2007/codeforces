import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val grid = Array(n) {
        tokenizer = StringTokenizer(jin.readLine())
        IntArray(m) { tokenizer.nextToken().toInt() }
    }
    val eastern = Array(n) { y ->
        val res = mutableMapOf<Int, Int>()
        val treeSet = TreeSet<Int>()
        for (x in 0 until m) {
            treeSet.add(grid[y][x])
        }
        var k = 0
        for (h in treeSet) {
            k++
            res[h] = k
        }
        res
    }
    val southern = Array(m) { x ->
        val res = mutableMapOf<Int, Int>()
        val treeSet = TreeSet<Int>()
        for (y in 0 until n) {
            treeSet.add(grid[y][x])
        }
        var k = 0
        for (h in treeSet) {
            k++
            res[h] = k
        }
        res
    }
    val out = StringBuilder()
    for (y in 0 until n) {
        for (x in 0 until m) {
            val h = grid[y][x]
            out.append(max(eastern[y][h]!!, southern[x][h]!!) + max(eastern[y].size - eastern[y][h]!!, southern[x].size - southern[x][h]!!))
            out.append(' ')
        }
        out.appendln()
    }
    print(out)
}