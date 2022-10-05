fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toLong() }
        var answer = "yEs"
        var curr = 0L
        var j = 0
        for (x in xs) {
            curr += x
            if (curr < 0L) {
                answer = "nO"
            }
            j++
            if (curr == 0L) {
                break
            }
        }
        if (curr != 0L) {
            answer = "No"
        }
        if (xs.subList(j, n).any { it != 0L }) {
            answer = "no"
        }
        println(answer)
    }
}