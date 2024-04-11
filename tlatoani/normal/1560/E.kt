fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val t = readLine()!!
        val order = mutableListOf<Char>()
        val freq = IntArray(26)
        for (letter in t.reversed()) {
            if (freq[letter - 'a'] == 0) {
                order.add(letter)
            }
            freq[letter - 'a']++
        }
        order.reverse()
        var length = 0
        for ((j, letter) in order.withIndex()) {
            length += freq[letter - 'a'] / (j + 1)
        }
        val s = t.substring(0, length)
        if (check(s, order, t)) {
            out.append(s).append(' ').appendln(order.joinToString(""))
        } else {
            out.appendln(-1)
        }
    }
    print(out)
}

fun check(s: String, order: List<Char>, t: String): Boolean {
    var j = 0
    val allowed = BooleanArray(26) { true }
    for (removedLetter in order) {
        for (letter in s) {
            if (allowed[letter - 'a']) {
                if (j >= t.length || letter != t[j]) {
                    return false
                }
                j++
            }
        }
        allowed[removedLetter - 'a'] = false
    }
    return j == t.length
}