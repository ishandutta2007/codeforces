fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var x = readLine()!!.toInt()
        if (x > 45) {
            println(-1)
        } else {
            var answer = ""
            for (d in 9 downTo 1) {
                if (x >= d) {
                    x -= d
                    answer = "$d$answer"
                }
            }
            println(answer)
        }
    }
}