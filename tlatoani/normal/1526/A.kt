fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }.sorted()
        println((0 until n).map { listOf(ay[it], ay[it + n]) }.flatten().joinToString(" "))
    }
}