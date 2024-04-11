fun main() {
    repeat(readInt()) {
        val (a, b) = readInts()
        println(a + b) 
    }
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map {it.toInt()}