fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var k = readLine()!!.toLong()
        if (k % 2L == 1L) {
            println(-1)
        } else {
            val answer = mutableListOf<Char>()
            for (h in 58 downTo 1) {
                while (k >= (1L shl (h + 1)) - 2L) {
                    k -= (1L shl (h + 1)) - 2L
                    answer.add('1')
                    for (j in 2..h) {
                        answer.add('0')
                    }
                }
            }
            println(answer.size)
            println(answer.joinToString(" "))
        }
    }
}