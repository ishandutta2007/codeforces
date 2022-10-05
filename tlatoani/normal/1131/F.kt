import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val left = IntArray(n + 1)
    val right = IntArray(n + 1)
    val leftMost = IntArray(n + 1) { it }
    val rightMost = IntArray(n + 1) { it }
    fun getLeftMost(a: Int): Int {
        if (leftMost[a] != leftMost[leftMost[a]]) {
            leftMost[a] = getLeftMost(leftMost[a])
        }
        return leftMost[a]
    }
    fun getRightMost(a: Int): Int {
        if (rightMost[a] != rightMost[rightMost[a]]) {
            rightMost[a] = getRightMost(rightMost[a])
        }
        return rightMost[a]
    }
    for (j in 2..n) {
        val line = jin.readLine().split(" ")
        val a = line[0].toInt()
        val b = line[1].toInt()
        val c = getRightMost(a)
        val d = getLeftMost(b)
        right[c] = d
        left[d] = c
        rightMost[c] = getRightMost(b)
        leftMost[d] = getLeftMost(a)
    }
    var a = 1
    while (left[a] != 0) {
        a = left[a]
    }
    val answer = mutableListOf<Int>()
    while (a != 0) {
        answer.add(a)
        a = right[a]
    }
    println(answer.joinToString(" "))
}