fun main() {
    val n = readLine()!!.toLong()
    var answer = (1L until n).filter { gcd(it, n) == 1L }.toMutableList()
    val product = answer.reduce { x, y -> (x * y) % n }
    if (product != 1L) {
        answer.remove(product)
    }
    println(answer.size)
    println(answer.joinToString(" "))
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)