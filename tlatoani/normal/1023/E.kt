fun main() {
    val n = readLine()!!.toInt()
    fun query(y1: Int, x1: Int, y2: Int, x2: Int): Boolean {
        if (y1 !in 1..n || x1 !in 1..n || y2 !in 1..n || x2 !in 1..n) {
            return false
        }
        println("? $y1 $x1 $y2 $x2")
        return readLine()!![0] == 'Y'
    }
    var y = 1
    var x = 1
    val beginning = StringBuilder()
    for (j in 2..n) {
        if (query(y + 1, x, n, n)) {
            y++
            beginning.append('D')
        } else {
            x++
            beginning.append('R')
        }
    }
    y = n
    x = n
    val end = StringBuilder()
    for (j in 2..n) {
        if (query(1, 1, y, x - 1)) {
            x--
            end.append('R')
        } else {
            y--
            end.append('D')
        }
    }
    println("! " + beginning.toString() + end.reversed())
}