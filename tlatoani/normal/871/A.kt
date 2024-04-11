fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        if (n % 2 == 0) {
            println(if (n < 4) -1 else (n / 4))
        } else {
            println(if (n < 13 && n != 9) -1 else ((n / 4) - 1))
        }
    }
}