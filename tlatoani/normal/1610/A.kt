fun main() {
    repeat(readLine()!!.toInt()) {
        println(readLine()!!.split(" ").map { it.toInt() }.map { if (it == 1) 0 else 1 }.sum())
    }
}