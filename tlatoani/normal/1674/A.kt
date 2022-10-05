fun main() {
    repeat(readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        if (y % x == 0) {
            println("1 ${y / x}")
        } else {
            println("0 0")
        }
    }
}