import java.util.*
import kotlin.math.min

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toLong()
    val m = tokenizer.nextToken().toInt()
    val k = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(readLine()!!)
    val x = tokenizer.nextToken().toLong()
    val s = tokenizer.nextToken().toLong()
    tokenizer = StringTokenizer(readLine()!!)
    val xn = LongArray(m) { tokenizer.nextToken().toLong() }
    tokenizer = StringTokenizer(readLine()!!)
    val c1 = LongArray(m) { tokenizer.nextToken().toLong() }
    tokenizer = StringTokenizer(readLine()!!)
    val ps = longArrayOf(0) + LongArray(k) { tokenizer.nextToken().toLong() }
    tokenizer = StringTokenizer(readLine()!!)
    val c2 = longArrayOf(0) + LongArray(k) { tokenizer.nextToken().toLong() }
    val spells1 = Array(m) { it }
    spells1.sortBy { c1[it] }
    var j = k
    while (c2[j] > s) {
        j--
    }
    var answer = (n - ps[j]) * x
    for (spell in spells1) {
        if (c1[spell] > s) {
            break
        }
        while (c1[spell] + c2[j] > s) {
            j--
        }
        answer = min(answer, (n - ps[j]) * xn[spell])
    }
    println(answer)
}