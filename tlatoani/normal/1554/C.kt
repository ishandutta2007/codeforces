fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        var answer = 0
        var bit = 1 shl 29
        while (bit > 0) {
            if ((answer xor n) or (bit - 1) <= m) {
                answer += bit
            }
            bit /= 2
        }
        println(answer)
    }
}