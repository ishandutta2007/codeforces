fun main() {
    repeat(readLine()!!.toInt()) {
        var answer = 0L
        for (d in 0..29) {
            val b = 1L shl d
            println("? ${b - answer} ${(3L * b) - answer}")
            if (readLine()!!.toLong() == 2L * b) {
                answer += b
            }
        }
        println("! $answer")
    }
}