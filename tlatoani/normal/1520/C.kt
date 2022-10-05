fun main() {
    val out = StringBuilder()
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        if (n == 2) {
            out.appendln(-1)
        } else {
            val answer = Array(n) { IntArray(n) }
            var x = 0
            for (dx in 0 until n) {
                for (dy in 0 until n) {
                    answer[(dx + dy) % n][(dy) % n] = (dx * n) + dy + 1
                }
                x = (x + n - 1 + 2) % n
            }
            answer.forEach { out.appendln(it.joinToString(" ")) }
        }
    }
    print(out)
}