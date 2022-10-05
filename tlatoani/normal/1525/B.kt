fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        println(when {
            ay.sorted() == ay -> 0
            ay.first() == ay.min()!! || ay.last() == ay.max()!! -> 1
            ay.first() == ay.max()!! && ay.last() == ay.min()!! -> 3
            else -> 2
        })
    }
}