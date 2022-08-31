import java.util.*

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts().toMutableList()
        data class Talk(val i: Int, val j: Int)
        val res = mutableListOf<Talk>()
        data class Index(val i: Int, val v: Int) : Comparable<Index> {
            override fun compareTo(other: Index): Int {
                if (v != other.v) {
                    return v.compareTo(other.v)
                }
                return i.compareTo(other.i)
            }
        }
        val s = TreeSet<Index>()
        for (i in 0 until n) {
            if (a[i] > 0) {
                s.add(Index(i, a[i]))
            }
        }
        while (s.size > 1) {
            val x = s.last().i
            s.remove(s.last())
            val y = s.last().i
            s.remove(s.last())
            res.add(Talk(x, y))
            for (z in listOf(x, y)) {
                a[z] -= 1
                if (a[z] > 0) {
                    s.add(Index(z, a[z]))
                }
            }
        }
        println(res.size)
        println(res.joinToString("\n") { "${it.i + 1} ${it.j + 1}" })
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }