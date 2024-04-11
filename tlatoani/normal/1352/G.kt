val ends = listOf(
        listOf(2, 4, 1, 3),
        listOf(2, 5, 3, 1, 4),
        listOf(2, 4, 6, 3, 5, 1),
        listOf(2, 4, 1, 5, 7, 3, 6)
)

fun main() {
    val out = StringBuilder()
    for (j in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        if (n <= 3) {
            out.appendln(-1)
        } else {
            for (j in 0..(n / 4) - 2) {
                for (k in 0..3) {
                    out.append(ends[0][k] + (4 * j)).append(' ')
                }
            }
            for (k in 0 until (n % 4) + 4) {
                out.append(ends[n % 4][k] + (n - (n % 4) - 4)).append(' ')
            }
            out.appendln()
        }
    }
    print(out)
}