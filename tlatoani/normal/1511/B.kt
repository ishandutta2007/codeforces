fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        var x = 1
        for (j in 2..c) {
            x *= 10
        }
        var y = x
        while (x.toString().length < a) {
            x *= 3
        }
        while (y.toString().length < b) {
            y *= 7
        }
        println("$x $y")
    }
}