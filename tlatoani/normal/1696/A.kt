fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, z) = readLine()!!.split(" ").map { it.toInt() }
        val xs = readLine()!!.split(" ").map { it.toInt() }
        println(xs.map { it or z }.maxOrNull()!!)
    }
}