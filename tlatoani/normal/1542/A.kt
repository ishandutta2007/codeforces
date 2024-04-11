fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        println(if (readLine()!!.split(" ").map { it.toInt() }.count { it % 2 == 1 } == n) "yEs" else "nO")
    }
}