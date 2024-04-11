import java.util.*

fun main() {
    val tokenizer = StringTokenizer(readLine()!!)
    val nums = LongArray(4) { tokenizer.nextToken().toLong() }
    val sum = nums.sum() / 3L
    for (j in 0..3) {
        if (nums[j] == sum) {
            val x = nums[(j + 1) % 4]
            val y = nums[(j + 2) % 4]
            val z = nums[(j + 3) % 4]
            println("${x + y - sum} ${y + z - sum} ${z + x - sum}")
            return
        }
    }
}