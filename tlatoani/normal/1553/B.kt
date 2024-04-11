fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val t = readLine()!!
        var answer = "nO"
        for (a in s.indices) {
            for (b in a until s.length) {
                if ((0 until b - a).all { j -> s[a + j] == t[j] } && (0 until t.length - (b - a)).all { j -> b - j >= 0 && s[b - j] == t[(b - a) + j] }) {
                    answer = "yEs"
                    break
                }
            }
        }
        println(answer)
    }
}