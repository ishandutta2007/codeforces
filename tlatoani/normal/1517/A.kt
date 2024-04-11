fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toLong()
        if (n % 2050L == 0L) {
            println((n / 2050L).toString().sumBy { it - '0' })
        } else {
            println(-1)
        }
    }
}