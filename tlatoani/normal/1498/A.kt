fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var n = readLine()!!.toLong()
        while (gcd(n, n.toString().sumBy { it - '0' }.toLong()) == 1L) {
            n++
        }
        println(n)
    }
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)