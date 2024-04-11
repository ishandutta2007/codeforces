fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }.sortedByDescending { it % 2 }
        var answer = 0
        for (j in 0 until n) {
            for (k in j + 1 until n) {
                if (gcd(2 * ay[j], ay[k]) > 1) {
                    answer++
                }
            }
        }
        println(answer)
    }
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)