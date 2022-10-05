fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        println("${x - 1} $y")
    }
}