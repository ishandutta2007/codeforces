fun main() {
    var n = read()
    var s = mutableSetOf<Int>()
    for (i in 1..9) s.add(i)
    while(n >= 10) {
        s.add(n)
        n++
        while(n%10 == 0) n/=10
    }
    println(s.size)
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}