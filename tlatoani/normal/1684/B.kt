fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        val x = c + (b - (c % b)) + a
        println("$x $b $c")
    }
}