fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val mine = readLine()!!.split(" ").map { it.toInt() }.sortedDescending()
        val deIlya = readLine()!!.split(" ").map { it.toInt() }.sortedDescending()
        var upper = n
        var lower = 0
        while (upper > lower) {
            val mid = (upper + lower) / 2
            //println("mid = $mid")
            var scoreMine = 0
            for (j in -mid until -mid + ((n + mid) - ((n + mid) / 4))) {
                scoreMine += if (j < 0) 100 else mine[j]
            }
            //println(scoreMine)
            var scoreDeIlya = 0
            for (j in 0 until ((n + mid) - ((n + mid) / 4))) {
                scoreDeIlya += if (j < n) deIlya[j] else 0
            }
            //println(scoreDeIlya)
            if (scoreMine >= scoreDeIlya) {
                upper = mid
            } else {
                lower = mid + 1
            }
        }
        println(upper)
    }
}