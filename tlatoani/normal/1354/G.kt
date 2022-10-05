import kotlin.math.min
import kotlin.random.Random
import kotlin.system.exitProcess

fun main() {
    val r = Random(System.currentTimeMillis())
    fun query(a: IntRange, b: IntRange): Int {
        println("? ${a.last - a.first + 1} ${b.last - b.first + 1}")
        println(a.joinToString(" "))
        println(b.joinToString(" "))
        val res = readLine()!![0]
        return when (res) {
            'F' -> 1
            'S' -> -1
            'E' -> 0
            else -> exitProcess(0)
        }
    }
    fun query(a: Int, b: Int): Int {
        println("? 1 1")
        println(a)
        println(b)
        val res = readLine()!![0]
        return when (res) {
            'F' -> 1
            'S' -> -1
            'E' -> 0
            else -> exitProcess(0)
        }
    }
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.substringBefore(' ').toInt()
        val stoneCandidates = (1..n).toMutableList()
        stoneCandidates.shuffle(r)
        var stone = stoneCandidates[0]
        for (j in 1 until min(25, n)) {
            if (query(stone, stoneCandidates[j]) < 0) {
                stone = stoneCandidates[j]
            }
        }
        if (stone != 1 && query(1, stone) < 0) {
            println("! 1")
        } else {
            var length = 1
            while (2 * length < n && query(length + 1..2 * length, 1..length) == 0) {
                length *= 2
            }
            for (e in 9 downTo 0) {
                if ((1 shl e) < length && length + (1 shl e) <= n && query(1..(1 shl e), length + 1..length + (1 shl e)) == 0) {
                    length += 1 shl e
                }
            }
            println("! ${length + 1}")
        }
    }
}