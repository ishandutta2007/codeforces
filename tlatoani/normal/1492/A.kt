fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!.split(" ").map { it.toLong() }
        println(line.subList(1, 4).map { it * ((line[0] + it - 1L) / it) }.min()!! - line[0])
    }
}