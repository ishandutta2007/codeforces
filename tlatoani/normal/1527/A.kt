fun main() {
    repeat(readLine()!!.toInt()) {
        var n = readLine()!!.toInt()
        var answer = 1
        while (n > 1) {
            answer *= 2
            n /= 2
        }
        answer--
        println(answer)
    }
}