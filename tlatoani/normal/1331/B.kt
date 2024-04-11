fun main() {
    val n = readLine()!!.toInt()
    for (p in 2..n) {
        if (n % p == 0) {
            print(p)
            println(n / p)
            return
        }
    }
}