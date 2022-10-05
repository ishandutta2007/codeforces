fun main() {
    repeat(readLine()!!.toInt()) {
        println(readLine()!!.split(" ").map { it.toInt() }.sum())
    }
}