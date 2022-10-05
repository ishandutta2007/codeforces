fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        println(a xor b)
    }
}