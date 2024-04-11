fun main() {
    var a1 = readInt()
    var a2 = readInt()
    var k1 = readInt()
    var k2 = readInt()
    var n = readInt()
    // (k1 - 1) * a1 + (k2 - 1) * a2
    val min = maxOf(0, n - ((k1 - 1) * a1 + (k2 - 1) * a2))
    if (k1 > k2) {
        a1 = a2.also{a2 = a1}
        k1 = k2.also{k2 = k1}
    }
    val max: Int
    if (n <= a1 * k1) {
        max = n / k1
    } else {
        max = (a1 + (n - a1 * k1) / k2)
    }
    println("$min $max")
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map {it.toInt()}