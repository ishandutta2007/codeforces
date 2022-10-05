fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        println(readLine()!!.split(" ").map { it.toInt() }.reduce { x, y -> x and y })
    }
}