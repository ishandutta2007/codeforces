fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val table = Array(n) { readLine()!!.map { it - '0' } }
        val l = (1 until n).any { y -> (1 until m).any { x -> table[y - 1][x - 1] + table[y - 1][x] + table[y][x - 1] + table[y][x] == 3 } }
        println(if (l) "nO" else "yEs")
    }
}