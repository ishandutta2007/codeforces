fun main() {
    val n = readLine()!!.toInt()
    println(if (n % 4 == 3 || n % 4 == 0) 0 else 1)
}