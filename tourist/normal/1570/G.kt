fun main() {
    println("? " + (1..100).joinToString(" "))
    val a = readInt()
    println("? " + (1..100).map {it shl 7}.joinToString(" "))
    val b = readInt()
    val x = (a shr 7 shl 7) + (b and ((1 shl 7) - 1))
    println("! $x")
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map {it.toInt()}