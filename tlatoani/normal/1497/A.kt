fun main() {
    for (c in 1..readLine()!!.toInt()) {
        readLine()
        val xs = readLine()!!.split(" ").map { it.toInt() }.sorted()
        val answer = xs.withIndex().map { (j, x) -> Pair(xs.indexOf(x) == j, x) }.sortedWith(compareBy({ !it.first }, { it.second })).map { it.second }
        println(answer.joinToString(" "))
    }
}