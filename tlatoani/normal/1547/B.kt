fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        var letter = s.max()!!
        var j = 0
        var k = s.lastIndex
        var answer = "yEs"
        while (letter >= 'a') {
            if (j > k) {
                answer = "nO"
                break
            }
            if (s[j] == letter) {
                j++
            } else if (s[k] == letter) {
                k--
            } else {
                answer = "nO"
                break
            }
            letter--
        }
        if (j <= k) {
            answer = "nO"
        }
        println(answer)
    }
}