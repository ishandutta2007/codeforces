fun main() {
    val out = StringBuilder()
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val field = Array(n) { readLine()!!.toCharArray() }
        val corners = mutableListOf<Pair<Int, Int>>()
        for (y in 0 until n) for (x in 0 until n) {
            if (field[y][x] == '*') {
                corners.add(Pair(y, x))
            }
        }
        val (y1, x1) = corners[0]
        val (y2, x2) = corners[1]
        if (y1 == y2) {
            field[(y1 + 1) % n][x1] = '*'
            field[(y2 + 1) % n][x2] = '*'
        } else if (x1 == x2) {
            field[y1][(x1 + 1) % n] = '*'
            field[y2][(x2 + 1) % n] = '*'
        } else {
            field[y1][x2] = '*'
            field[y2][x1] = '*'
        }
        field.forEach { out.appendln(it) }
    }
    print(out)
}