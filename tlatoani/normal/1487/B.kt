fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        println(if (n % 2 == 0) (((k - 1) % n) + 1) else ((((((k - 1) / ((n - 1) / 2)) * ((n + 1) / 2)) + ((k - 1) % ((n - 1) / 2))) % n) + 1))
    }
}