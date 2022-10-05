import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val elems = readLine()!!.split(" ").map { it.toInt() }.sorted()
    fun recur(bit: Int, from: Int, to: Int): Int = when {
            bit == 1 -> to - from + 1
            elems[from] and bit == elems[to] and bit -> recur(bit / 2, from, to)
            else -> {
                val mid = (from..to).last { elems[it] and bit == 0 }
                1 + max(recur(bit / 2, from, mid), recur(bit / 2, mid + 1, to))
            }
    }
    println(n - recur(1 shl 29, 0, n - 1))
}