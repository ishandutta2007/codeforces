fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        fun query(left: Iterable<Int>, right: Iterable<Int>): Int {
            val left = left.toList()
            val right = right.toList()
            println("? ${left.size} ${right.size}")
            println(left.joinToString(" "))
            println(right.joinToString(" "))
            return readLine()!!.toInt()
        }
        val answer = mutableListOf<Int>()
        var secondNonZero = 0
        for (j in 2..n) {
            if (secondNonZero == 0) {
                if (query(1 until j, listOf(j)) != 0) {
                    secondNonZero = j
                }
            } else {
                if (query(1 until secondNonZero, listOf(j)) == 0) {
                    answer.add(j)
                }
            }
        }
        var upper = secondNonZero - 1
        var lower = 1
        while (upper > lower) {
            val mid = (upper + lower) / 2
            if (query(1..mid, listOf(secondNonZero)) == 0) {
                lower = mid + 1
            } else {
                upper = mid
            }
        }
        answer.addAll(1 until upper)
        answer.addAll(lower + 1 until secondNonZero)
        println("! ${answer.size} ${answer.joinToString(" ")}")
    }
}