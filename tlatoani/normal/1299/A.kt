import java.util.*

fun main() {
    val ALL = (1L shl 32) - 1L
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val array = LongArray(n) { tokenizer.nextToken().toLong() }
    val prefix = LongArray(n + 1)
    for (j in 1..n) {
        prefix[j] = prefix[j - 1] or array[j - 1]
    }
    val suffix = LongArray(n + 1)
    for (j in n - 1 downTo 0) {
        suffix[j] = suffix[j + 1] or array[j]
    }
    var optimal = 0L
    var ix = -1
    for (j in 0 until n) {
        val pos = array[j] and (ALL xor (prefix[j] or suffix[j + 1]))
        if (pos >= optimal) {
            optimal = pos
            ix = j
        }
    }
    val temp = array[ix]
    array[ix] = array[0]
    array[0] = temp
    println(array.joinToString(" "))
}