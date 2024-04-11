fun main() {
    val t = readLine()!!.toInt()
    for (c in 1..t) {
        val n = readLine()!!.toInt()
        if (n < 1000) {
            println(n)
        } else if (n < 999500) {
            print((n + 500) / 1000)
            println("K")
        } else {
            print((n + 500000) / 1000000)
            println("M")
        }
    }
}