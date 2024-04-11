import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val nums = IntArray(n) { jin.nextInt() }
    nums.sort()
    val colored = BooleanArray(n) { false }
    var colors = 0
    for (i in 0 until n) {
        if (!colored[i]) {
            colors++
            for (j in 0 until n) {
                if (nums[j] % nums[i] == 0) {
                    colored[j] = true
                }
            }
        }
    }
    println(colors)
}