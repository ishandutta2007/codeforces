fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(" ").map { it.toLong() }
        if (b == 1L) {
            println("nO")
        } else {
            println("yEs")
            println("$a ${a * ((2L * b) - 1)} ${2L * a * b}")
        }
    }
}