import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val a = jin.nextInt()
    val b = jin.nextInt()
    var g = jin.nextLong()
    val x = jin.nextLong()
    val y = jin.nextLong()
    val z = jin.nextLong()
    val map = Array(n) { LongArray(m) {
        val res = g
        g = ((g * x) + y) % z
        res
    }}
    val mins = Array(n) { LongArray(m) }
    for (i in 0 until n) {
        val queue = LinkedList<Int>()
        for (j in 0 until b) {
            while (!queue.isEmpty() && map[i][queue.last] >= map[i][j]) {
                queue.removeLast()
            }
            queue.add(j)
        }
        for (j in 0..m - b) {
            if (queue.first < j) {
                queue.remove()
            }
            mins[i][j] = map[i][queue.first]
            if (j + b < m) {
                while (!queue.isEmpty() && map[i][queue.last] >= map[i][j + b]) {
                    queue.removeLast()
                }
                queue.add(j + b)
            }
        }
    }
    var answer: Long = 0
    for (j in 0 until m) {
        val queue = LinkedList<Int>()
        for (i in 0 until a) {
            while (!queue.isEmpty() && mins[queue.last][j] >= mins[i][j]) {
                queue.removeLast()
            }
            queue.add(i)
        }
        for (i in 0..n - a) {
            if (queue.first < i) {
                queue.remove()
            }
            answer += mins[queue.first][j]
            if (i + a < n) {
                while (!queue.isEmpty() && mins[queue.last][j] >= mins[i + a][j]) {
                    queue.removeLast()
                }
                queue.add(i + a)
            }
        }
    }
    println(answer)
}