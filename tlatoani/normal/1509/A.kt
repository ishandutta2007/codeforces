fun main() {
    for ( in 1..readLine()!!.toInt()) {
        readLine()
        println(readLine()!!.split(" ").map { it.toInt() }.sortedBy { it % 2 }.joinToString(" "))
    }
}