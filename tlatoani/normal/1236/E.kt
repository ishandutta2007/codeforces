import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    if (n == 1) {
        println(0)
        return
    }
    val fromBelow = IntArray(n + m + 1) { j -> if (j < m + 1) 0 else 1 }
    val fromAbove = IntArray(n + m + 1) { j -> if (j < n) 1 else 0 }
    var k = 0
    for (j in 1..m) {
        k = jin.nextInt() - 1
        fromBelow[m + 1 + k - j - 1] += fromBelow[m + 1 + k - j]
        fromBelow[m + 1 + k - j] = 0
        fromAbove[k + j + 1] += fromAbove[k + j]
        fromAbove[k + j] = 0
    }
    val upperBounds = mutableListOf<Int>()
    for (l in 0..n + m) {
        for (j in 1..fromBelow[l]) {
            upperBounds.add(min(n - 1, l))
        }
    }
    val lowerBounds = mutableListOf<Int>()
    for (l in 0..n + m) {
        for (j in 1..fromAbove[l]) {
            lowerBounds.add(max(0, l - m - 1))
        }
    }
    //println("lowerBounds = $lowerBounds, upperBounds = $upperBounds")
    var answer = 0L
    for (l in 0 until n) {
        answer += (upperBounds[l] - lowerBounds[l] + 1).toLong()
        /*if (k >= lowerBounds[l] && k <= upperBounds[l]) {
            answer--
        }*/
    }
    println(answer)
}