fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val by = readLine()!!.split(" ").map { it.toInt() }
        println(IntArray(n) { if (it % 2 == 0) by[it / 2] else by[n - 1 - (it / 2)] }.joinToString(" "))
    }
}