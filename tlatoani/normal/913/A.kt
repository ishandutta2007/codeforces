fun main() {
    val n = readLine()!!.toInt()
    val m = readLine()!!.toInt()
    if (n <= 30) {
        println(m % (1 shl n))
    } else {
        println(m)
    }
}