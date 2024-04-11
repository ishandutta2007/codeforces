fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }.sorted()
        println(if (1 in xs && (1 until xs.size).any { xs[it] - xs[it - 1] == 1 }) "nO" else "yEs")
    }
}