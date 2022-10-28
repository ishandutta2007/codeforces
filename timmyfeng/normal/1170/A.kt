fun main() {
    val q = readLine()!!.toInt()
    for (i in 0 until q) {
        var (a, b) = readLine()!!.split(" ").map { it.toInt() }
        if (a > b) {
            val tmp = a
            a = b
            b = tmp
        }
        println("1 ${a - 1} ${b - a + 1}")
    }
}