fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val heroes = readLine()!!.split(" ").map { it.toInt() }
        println(heroes.count { it != heroes.min() })
    }
}