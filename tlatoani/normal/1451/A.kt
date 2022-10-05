fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        println(when {
            n == 1 -> 0
            n == 2 -> 1
            n % 2 == 0 -> 2
            n == 3 -> 2
            else -> 3
        })
    }
}