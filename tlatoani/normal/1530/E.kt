fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val freqs = IntArray(26)
        val s = readLine()!!
        for (letter in s) {
            freqs[letter - 'a']++
        }
        fun freq(letter: Char) = freqs[letter - 'a']
        fun output(letter: Char, amt: Int) {
            out.append(letter.toString().repeat(amt))
            freqs[letter - 'a'] -= amt
        }
        val letters = ('a'..'z').filter { freq(it) > 0 }
        if (letters.size == 1) {
            out.append(s)
        } else if (letters.any { freq(it) == 1 }) {
            val firstLetter = letters.filter { freq(it) == 1 }.min()!!
            out.append(firstLetter)
            out.append(s.replace(firstLetter.toString(), "").toList().sorted().toCharArray())
        } else if (freq(letters[0]) - 2 <= freqs.sum() - freq(letters[0])) {
            output(letters[0], 2)
            for (letter in s.replace(letters[0].toString(), "").toList().sorted()) {
                output(letter, 1)
                if (freq(letters[0]) > 0) {
                    output(letters[0], 1)
                }
            }
        } else {
            output(letters[0], 1)
            output(letters[1], 1)
            if (letters.size > 2) {
                output(letters[0], freq(letters[0]))
                output(letters[2], 1)
                for (letter in letters) {
                    output(letter, freq(letter))
                    out.append(letter.toString().repeat(freq(letter)))
                }
            } else {
                output(letters[1], freq(letters[1]))
                output(letters[0], freq(letters[0]))
            }
        }
        out.appendln()
    }
    print(out)
}