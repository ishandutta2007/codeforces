import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val tokenizer = StringTokenizer(readLine()!!)
        val amts = LongArray(3) { tokenizer.nextToken().toLong() }
        println(if (amts.max()!! > (amts.sum() + 1L) / 2L) "No" else "Yes")
    }
}