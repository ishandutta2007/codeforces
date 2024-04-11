fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        var (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!
        val decreased = mutableSetOf<Char>()
        decreased.add('a')
        for (letter in s) {
            var letter = letter
            while (k > 0 && letter !in decreased) {
                k--
                decreased.add(letter)
                letter--
            }
        }
        val answer = s.toCharArray()
        decreased.remove('a')
        for (j in answer.indices) {
            while (answer[j] in decreased) {
                answer[j]--
            }
        }
        out.appendln(answer)
    }
    print(out)
}