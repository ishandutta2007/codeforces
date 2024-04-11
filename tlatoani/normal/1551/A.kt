fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        println("${(n / 3) + (if (n % 3 == 1) 1 else 0)} ${(n / 3) + (if (n % 3 == 2) 1 else 0)}")
    }
}