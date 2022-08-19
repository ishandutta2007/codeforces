fun main(args: Array<String>) {
    val tt = readLine()!!.toInt()
    for (qq in 0 until tt) {
        var (x, y) = readLine()!!.split(" ").map { it.toInt() }
        if (x < y) {
            var z = x
            x = y
            y = z
        }
        println((x - y + 1).toString() + " " + 1.toString() + " " + (y - 1).toString())
    }
}