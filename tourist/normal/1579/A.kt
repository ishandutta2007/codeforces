fun main() {
    val t = readInt()
    repeat(t) {
        val s = readLn()
        val cntB = s.count { it == 'B' }
        val cntRest = s.count { it != 'B' }
        println(if (cntB == cntRest) "YES" else "NO")
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }