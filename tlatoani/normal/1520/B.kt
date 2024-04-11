fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var answer = 0
        for (l in 1..9) {
            for (d in 1..9) {
                if (d.toString().repeat(l).toInt() <= n) {
                    answer++
                }
            }
        }
        println(answer)
    }
}