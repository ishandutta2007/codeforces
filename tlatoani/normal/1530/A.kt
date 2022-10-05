fun main() {
    repeat(readLine()!!.toInt()) {
        println(readLine()!!.map { it - '0' }.max())
    }
}