fun main() {
    val n = readLine()!!.toInt()
    var spectator = 3
    for (j in 1..n) {
        var winner = readLine()!!.toInt()
        if (winner == spectator) {
            println("NO")
            return
        }
        spectator = 6 - spectator - winner
    }
    println("YES")
}