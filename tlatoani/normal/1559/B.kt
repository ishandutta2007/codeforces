fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val s = readLine()!!.toCharArray()
        if (s.all { it == '?' }) {
            s[0] = 'R'
        }
        val j = s.indexOfFirst { it != '?' }
        for (k in j - 1 downTo 0) {
            s[k] = if (s[k + 1] == 'R') 'B' else 'R'
        }
        for (k in s.indices) {
            if (s[k] == '?') {
                s[k] = if (s[k - 1] == 'R') 'B' else 'R'
            }
        }
        println(s)
    }
}