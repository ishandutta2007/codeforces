fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, x) = readLine()!!.split(" ").map { it.toInt() }
        val ay = readLine()!!.split(" ").map { it.toInt() }
        if (n >= 2 * x) {
            println("yEs")
        } else if (n <= x) {
            println(if (ay == ay.sorted()) "yEs" else "nO")
        } else {
            val by = (ay.subList(0, n - x) + ay.subList(x, n)).sorted()
            val res = by.subList(0, n - x) + ay.subList(n - x, x) + by.subList(n - x, by.size)
            println(if (res == ay.sorted()) "yEs" else "nO")
        }
    }
}