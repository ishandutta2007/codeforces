fun main() {
    val out = StringBuilder()
    fun output(s: String, startingLetter: Char) = out.append(s
            .replace('d', startingLetter + 3)
            .replace('c', startingLetter + 2)
            .replace('b', startingLetter + 1)
            .replace('a', startingLetter))
    fun generate(n: Int, startingLetter: Char = 'a') {
        when {
            n == 0 -> Unit
            n == 3 -> output("abc", startingLetter)
            n == 6 -> output("aabacd", startingLetter)
            n == 1 -> output("a", startingLetter)
            n == 4 -> output("aaba", startingLetter)
            n == 7 -> output("aabaaac", startingLetter)
            n == 10 -> output("aabaaacdbb", startingLetter)
            n % 3 == 2 -> {
                fun rem() = generate((n - 2) / 3, startingLetter + 2)
                rem()
                output("a", startingLetter)
                rem()
                output("b", startingLetter)
                rem()
            }
            n % 3 == 0 -> {
                fun rem() = generate((n - 6) / 3, startingLetter + 2)
                rem()
                output("aab", startingLetter)
                rem()
                output("bba", startingLetter)
                rem()
            }
            n % 3 == 1 -> {
                fun rem() = generate((n - 10) / 3, startingLetter + 2)
                rem()
                output("aaabb", startingLetter)
                rem()
                output("bbbaa", startingLetter)
                rem()
            }
        }
    }
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        generate(n)
        out.appendln()
    }
    print(out)
}