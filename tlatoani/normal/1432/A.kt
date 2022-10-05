fun main() {
    for (c in 1..readLine()!!.toInt()) {
        println(readLine()!!.split(" ").map { it.toInt() }.sum())
    }
}