fun main() {
    var a1 = read()
    var a2 = read()
    var k1 = read()
    var k2 = read()
    var n = read()
    if (k1 > k2) {
        k1 = k2.also {k2=k1}
        a1 = a2.also {a2=a1}
    }
    print(maxOf(0, n-a1*(k1-1)-a2*(k2-1)))
    print(" ")
    var red1 = minOf(a1, n/k1)
    n -= red1*k1
    println(red1 + minOf(a2, n/k2))
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}