import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    jin.nextInt()
    val sequence = IntArray(n) { jin.nextInt() }
    val left = IntArray(200001) { n }
    val right = IntArray(200001) { -1 }
    for (i in 0 until n) {
        if (left[sequence[i]] == n) {
            left[sequence[i]] = i
        }
        right[sequence[i]] = i
    }
    var i = 0
    var difficulty = 0
    while (i < n) {
        val amt = mutableMapOf<Int, Int>()
        var upper = right[sequence[i]]
        while (i <= upper) {
            amt[sequence[i]] = (amt[sequence[i]] ?: 0) + 1
            upper = max(upper, right[sequence[i]])
            i++
        }
        difficulty += amt.values.sum() - amt.values.max()!!
    }
    println(difficulty)
}