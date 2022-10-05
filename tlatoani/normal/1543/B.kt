fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toLong()
        val s = readLine()!!.split(" ").map { it.toLong() }.sum()
        val x = s % n
        println(x * (n - x))
    }
}