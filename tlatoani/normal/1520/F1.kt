fun main() {
    val (n, t) = readLine()!!.split(" ").map { it.toInt() }
    val k = readLine()!!.toInt()
    fun query(from: Int, to: Int): Int {
        println("? $from $to")
        return (to - from + 1) - readLine()!!.toInt()
    }
    var lower = 1
    var upper = n
    while (upper > lower) {
        val mid = (upper + lower) / 2
        if (query(1, mid) >= k) {
            upper = mid
        } else {
            lower = mid + 1
        }
    }
    println("! $lower")
}