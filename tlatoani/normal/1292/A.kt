fun main() {
    var line = readLine()!!
    var six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val q = line.substring(six + 1).toInt()
    val maze = Array(2) { BooleanArray(n) { true } }
    var blocked = 0
    val out = StringBuilder()
    for (j in 1..q) {
        line = readLine()!!
        six = line.indexOf(' ')
        val r = line.substring(0, six).toInt() - 1
        val c = line.substring(six + 1).toInt() - 1
        if (c > 0 && !(maze[0][c - 1] && maze[0][c]) && !(maze[1][c - 1] && maze[1][c])) {
            blocked--
        }
        if (c < n - 1 && !(maze[0][c + 1] && maze[0][c]) && !(maze[1][c + 1] && maze[1][c])) {
            blocked--
        }
        maze[r][c] = !maze[r][c]
        if (c > 0 && !(maze[0][c - 1] && maze[0][c]) && !(maze[1][c - 1] && maze[1][c])) {
            blocked++
        }
        if (c < n - 1 && !(maze[0][c + 1] && maze[0][c]) && !(maze[1][c + 1] && maze[1][c])) {
            blocked++
        }
        out.appendln(if (blocked == 0) "yEs" else "nO")
    }
    print(out)
}