fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        var answer = 0
        var amt1After = s.count { it == '1' }
        for (friend in s) {
            if (friend == '1') {
                amt1After--
            }
            if (amt1After == 0) {
                answer++
            }
            if (friend == '0') {
                break
            }
        }
        println(answer)
    }
}