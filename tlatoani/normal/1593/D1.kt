fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        if (xs.toSet().size == 1) {
            println(-1)
        } else {
            val m = xs.min()!!
            var answer = 0
            for (x in xs) {
                answer = gcd(answer, x - m)
            }
            println(answer)
        }
    }
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)