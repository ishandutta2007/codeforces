fun main() {
    var n = readInt()
    val s = HashSet<Int>()
    while (!s.contains(n)) {
        s.add(n)
        n += 1
        while (n % 10 == 0) {
            n /= 10
        }
    }
    println(s.size)
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map {it.toInt()}