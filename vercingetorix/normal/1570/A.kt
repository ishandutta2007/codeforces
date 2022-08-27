fun main() {
    repeat(read()) {
        val (a, b) = readv()
        println(a + b)
    }
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}