fun main() {
    repeat(readLine()!!.toInt()) {
        val (h, w) = readLine()!!.split(" ").map { it.toInt() }
        val answer = Array(h) { CharArray(w) { '0' } }
        answer[0][0] = '1'
        answer[0][w - 1] = '1'
        answer[h - 1][0] = '1'
        answer[h - 1][w - 1] = '1'
        for (x in 1..w - 2) {
            for (y in listOf(0, h - 1)) {
                if (answer[y][x - 1] == '0' && answer[y][x + 1] == '0') {
                    answer[y][x] = '1'
                }
            }
        }
        for (y in 1..h - 2) {
            for (x in listOf(0, w - 1)) {
                if (answer[y - 1][x] == '0' && answer[y + 1][x] == '0') {
                    answer[y][x] = '1'
                }
            }
        }
        answer.forEach { println(it) }
        println()
    }
}