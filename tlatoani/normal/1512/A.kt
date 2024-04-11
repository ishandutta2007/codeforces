fun main() {
    for (c in 1..readLine()!!.toInt()) {
        readLine()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        println(ay.indexOfFirst { x -> ay.count { y -> x == y } == 1 } + 1)
    }
}