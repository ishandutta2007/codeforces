fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (h, m) = readLine()!!.split(" ").map { it.toInt() }
        var (x, y) = readLine()!!.split(":").map { it.toInt() }
        while (reverse(y) !in 0 until h || reverse(x) !in 0 until m) {
            y++
            if (y == m) {
                y = 0
                x++
            }
            if (x == h) {
                x = 0
            }
        }
        println("${x / 10}${x % 10}:${y / 10}${y % 10}")
    }
}

val reversed = mapOf(
        0 to 0,
        1 to 1,
        2 to 5,
        5 to 2,
        8 to 8
)

fun reverse(x: Int): Int {
    val a = x / 10
    val b = x % 10
    return if (a in reversed && b in reversed) {
        (10 * reversed[b]!!) + reversed[a]!!
    } else {
        -1
    }
}