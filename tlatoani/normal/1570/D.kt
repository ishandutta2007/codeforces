fun main() {
    var n = readLine()!!.toInt()
    val reachable = mutableSetOf<Int>()
    while (n !in reachable) {
        reachable.add(n)
        n++
        while (n % 10 == 0) {
            n /= 10
        }
    }
    println(reachable.size)
}